#include "basiccellstate.h"

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

void BasicCellState::hintCell(Cell &obj)
{
    int flag = obj.mTypeCell;
    ++flag;
    flag = flag%3;
    switch (flag) {
    case 1:
        obj.mTypeCell = ImageType::Flag;
        break;
    case 2:
        obj.mTypeCell = ImageType::Quastion;
        break;
    default:
        obj.mTypeCell = ImageType::Basic;
        break;
    }
    obj.updateGrpahic();
}
