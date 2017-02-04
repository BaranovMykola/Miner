#include "cell.h"

#include <QDebug>
#include <QEvent>
#include <QMouseEvent>


Cell::Cell(QWidget *parent) : QWidget(parent),
    mTypeCell(ImageType::Basic)
{
    mGraphic.setParent(this);
    updateGrpahic();
    state = std::make_unique<BasicCellState>(BasicCellState());
}

void Cell::enterEvent(QEvent *event)
{
    state->changeCell(*this, MinimizeCellSize);
}

void Cell::leaveEvent(QEvent *event)
{
    state->changeCell(*this, RealCellSize);
}

void Cell::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        state->clickOn(*this);
    }
    else
    {
        state->hintCell(*this);
    }
}

void Cell::show()
{
    mGraphic.show();
}

void Cell::setMine(bool mine)
{
    mMine = mine;
}

bool Cell::isMine() const
{
    return mMine;
}

void Cell::updateGrpahic()
{
    mGraphic.setPixmap(QPixmap(GraphicsFile.at(mTypeCell)));
}

void Cell::resizeCell(int toSize)
{
    auto pxm = mGraphic.pixmap();
    mGraphic.setPixmap(pxm->scaledToHeight(toSize));
}


