#ifndef STEPPEDCELLSTATE_H
#define STEPPEDCELLSTATE_H

#include "abstractcellstate.h"

class SteppedCellState : public AbstractCellState
{
public:
    void clickOn(Cell& obj);
    void changeCell(Cell& obj, int toSize);
};

#endif // STEPPEDCELLSTATE_H
