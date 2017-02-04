#include "miner.h"
#include "ui_miner.h"

Miner::Miner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Miner)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    this->setFixedSize(Width*(RealCellSize+CellsDistance), Height*(RealCellSize+CellsDistance));
    ui->fieldBox->addLayout(mMineField.getField());

}

Miner::~Miner()
{
    delete ui;
}
