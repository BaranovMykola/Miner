#include "miner.h"
#include "ui_miner.h"

#include <QDebug>
#include <QMessageBox>

Miner::Miner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Miner),
    mMineField(this),
    mSun(mMineField, this)
{
    ui->setupUi(this);
//    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    mMineField.setMine(3);
    ui->fieldBox->addLayout(mMineField.getField());
    connect(&mMineField, &GridField::loose, [this](){slotUpdateSunImage(SunType::ExplodedSun);});
    connect(&mMineField, &GridField::mouseClicked, [this](){slotUpdateSunImage(SunType::Kiss);});
    connect(&mMineField, &GridField::mouseCLickReleased, [this](){slotUpdateSunImage(SunType::BasicSun);});
    connect(&mMineField, SIGNAL(loose()), this, SLOT(slotLose()), Qt::UniqueConnection);
    mSun.updateGrpahic();
    ui->sunlayout->addWidget(&mSun);
    getSmartSize();
}

Miner::~Miner()
{
    delete ui;
}

void Miner::getSmartSize()
{
    this->adjustSize();
    this->setFixedHeight(this->height());
    this->setFixedWidth(this->width());
}

void Miner::slotUpdateSunImage(SunType type)
{
    mSun.setImage(type);
}

void Miner::slotLose()
{
    QMessageBox message;
    message.setWindowTitle("You lose!");
    message.setText("You have lose! Try again...");
    message.setIconPixmap(QPixmap(GraphicsFile.at(ImageType::Exploded)));
    message.exec();
    mSun.setEnabled(true);
}
