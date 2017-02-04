#include "miner.h"
#include "ui_miner.h"

#include <QDebug>

Miner::Miner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Miner)
{
    ui->setupUi(this);
//    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    mMineField.setMine(1);
    ui->fieldBox->addLayout(mMineField.getField());
}

Miner::~Miner()
{
    delete ui;
}
