#ifndef MINER_H
#define MINER_H

#include <QMainWindow>

#include "gridfield.h"

const int CellsDistance = 8;

namespace Ui {
class Miner;
}

class Miner : public QMainWindow
{
    Q_OBJECT

public:
    explicit Miner(QWidget *parent = 0);
    ~Miner();

private:
    Ui::Miner *ui;
    GridField mMineField;
};

#endif // MINER_H
