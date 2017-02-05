#include "miner.h"
#include "ui_miner.h"

#include <QDebug>

Miner::Miner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Miner)
{
    ui->setupUi(this);
//    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    mMineField.setMine(10);
    ui->fieldBox->addLayout(mMineField.getField());
    this->setFixedHeight(ui->sun->height()+Height*(CellLayoutWidth));
    this->setFixedWidth(Width*CellLayoutWidth);
    connect(&mMineField, SIGNAL(explodeSun()), this, SLOT(slotSunExploded()), Qt::UniqueConnection);
    connect(&mMineField, SIGNAL(mouseClicked()), this, SLOT(slotSunKiss()), Qt::UniqueConnection);
    connect(&mMineField, SIGNAL(mouseCLickReleased()), this, SLOT(slotSunReset()), Qt::UniqueConnection);
}

Miner::~Miner()
{
    delete ui;
}

void Miner::slotSunExploded()
{
    ui->sun->setPixmap(QPixmap(":/sun/resources/sun_e.png"));
}

void Miner::slotSunKiss()
{
    ui->sun->setPixmap(QPixmap(":/sun/resources/sun_k.png"));
}

void Miner::slotSunReset()
{
    ui->sun->setPixmap(QPixmap(":/sun/resources/sun.png"));
}
