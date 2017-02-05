#ifndef MINER_H
#define MINER_H

#include <QMainWindow>

#include "gridfield.h"
#include "sun.h"

const int CellsStretchFactor = 3;
const int CellLayoutWidth = RealCellSize+CellsStretchFactor;

namespace Ui {
class Miner;
}

class Miner : public QMainWindow
{
    Q_OBJECT

public:
    explicit Miner(QWidget *parent = 0);
    ~Miner();
    void getSmartSize();
public slots:
    void slotUpdateSunImage(SunType type);
    void slotLose();
private:
    Ui::Miner *ui;
    GridField mMineField;
    Sun mSun;
};

#endif // MINER_H
