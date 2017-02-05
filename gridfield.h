#ifndef GRIDFIELD_H
#define GRIDFIELD_H

#include <QWidget>
#include <QLayout>

#include <vector>

#include "cell.h"

const int Width = 10;
const int Height = 10;

class GridField : public QWidget
{
    Q_OBJECT
public:
    explicit GridField(QWidget* parent = 0);
    QVBoxLayout *getField();
    void setMine(int count);
    void updateBesideCells(int w, int h);
    void resetCells();
    void resetGridField(int minesCount);
signals:
    void explodeSun();
    void mouseClicked();
    void mouseCLickReleased();
public slots:
    void slotStepOn(int w, int h);
    void slotMine();
    void slotClickReleased();
private:
    bool isCorrect(int w, int h);
    std::pair<int, int> getPosition(Cell* _cell);
    std::vector<std::vector<Cell*>> cells;
    QVBoxLayout mField;
};

#endif // GRIDFIELD_H
