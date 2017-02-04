#ifndef STEPPEDCELLSTATE_H
#define STEPPEDCELLSTATE_H

#include "abstractcellstate.h"

class SteppedCellState : public AbstractCellState
{
public:
    void clickOn(Cell& obj);
    void changeCell(Cell& obj, int toSize);
    void hintCell(Cell&obj);
};

#endif // STEPPEDCELLSTATE_H
