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
    connect(&mMineField, SIGNAL(explodeSun()), this, SLOT(slotSunExploded()), Qt::UniqueConnection);
}

Miner::~Miner()
{
    delete ui;
}

void Miner::slotSunExploded()
{
    ui->sun->setPixmap(QPixmap(":/sun/resources/sun_e.png"));
}
