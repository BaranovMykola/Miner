#include "miner.h"
#include "ui_miner.h"

#include "cell.h"

Miner::Miner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Miner)
{
    ui->setupUi(this);
    Cell* c = new Cell(this);
    c->show();
}

Miner::~Miner()
{
    delete ui;
}
