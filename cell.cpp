#include "cell.h"

#include <QDebug>
#include <QEvent>
#include <QMouseEvent>


Cell::Cell(QWidget *parent) :
    AbstractCell(parent),
    mTypeCell(ImageType::Basic),
    mMineBeside(0),
    mMine(false)
{
    updateGrpahic();
    state = std::make_unique<BasicCellState>(BasicCellState());
    connect(this, SIGNAL(mouseClickedMineButton()), this, SLOT(slotStep()), Qt::UniqueConnection);
    connect(this, SIGNAL(mouseClicked()), this, SLOT(slotFlag()), Qt::UniqueConnection);
    connect(this, SIGNAL(mouseHovered()), this, SLOT(slotAnimationOn()), Qt::UniqueConnection);
    connect(this, SIGNAL(mouseReleased()), this, SLOT(slotAnimationOff()), Qt::UniqueConnection);
    connect(this, SIGNAL(mouseClickReleased()), this, SLOT(slotMouseClickReleased()), Qt::UniqueConnection);
}

void Cell::setMine(bool mine)
{
    mMine = mine;
}

bool Cell::isMine() const
{
    return mMine;
}

void Cell::open()
{
    if(isMine())
    {
        mTypeCell = ImageType::Exploded;
    }
    else
    {
        switch (mMineBeside)
        {
            case 1:
                mTypeCell = ImageType::One;
                break;
            case 2:
                mTypeCell = ImageType::Two;
                break;
            case 3:
                mTypeCell = ImageType::Three;
                break;
            case 4:
                mTypeCell = ImageType::Four;
                break;
            case 5:
                mTypeCell = ImageType::Five;
                break;
            case 6:
                mTypeCell = ImageType::Six;
                break;
            case 7:
                mTypeCell = ImageType::Seven;
                break;
            case 8:
                mTypeCell = ImageType::Eight;
                break;
            default:
                mTypeCell = ImageType::Empty;
                break;
        }
    }
    updateGrpahic();
}

void Cell::reset()
{
    mMine = false;
    mTypeCell = ImageType::Basic;
    state.reset();
    resetState();
    mMineBeside = 0;
    updateGrpahic();
}

void Cell::resetState()
{
    state = std::make_unique<BasicCellState>(BasicCellState());

}

void Cell::slotStep()
{
    state->clickOn(*this);
}

void Cell::slotFlag()
{
    state->hintCell(*this);
}

void Cell::slotAnimationOn()
{
    state->changeCell(*this, MinimizeCellSize);
}

void Cell::slotAnimationOff()
{
    state->changeCell(*this, RealCellSize);
}

void Cell::slotMouseClickReleased()
{
    if(!isMine())
    {
        emit endKiss();
    }
}

void Cell::updateGrpahic()
{
    AbstractCell::updateGrpahic(GraphicsFile.at(mTypeCell));
}


