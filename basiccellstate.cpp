#include "basiccellstate.h"

#include "cell.h"
#include "steppedcellstate.h"

void BasicCellState::clickOn(Cell &obj)
{
    obj.state = std::make_unique<SteppedCellState>(SteppedCellState());
    obj.resizeCell(RealCellSize);
    delete this;
}

void BasicCellState::changeCell(Cell &obj, int toSize)
{
    obj.resizeCell(toSize);
}
