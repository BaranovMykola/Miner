#include "miner.h"
#include "ui_miner.h"

Miner::Miner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Miner)
{
    ui->setupUi(this);
}

Miner::~Miner()
{
    delete ui;
}
