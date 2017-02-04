#include "cell.h"

#include <QDebug>
#include <QEvent>



Cell::Cell(QWidget *parent) : QWidget(parent)
{
    mGraphic.setParent(this);
    mGraphic.setPixmap(QPixmap(GraphicsFile.at(ImageType::Seven)));
    connect(this, SIGNAL(signalHoveredOn()), this, SLOT(slotHovered()), Qt::UniqueConnection);
    state = std::make_unique<BasicCellState>(BasicCellState());
//    new BasicCellState;
}

void Cell::enterEvent(QEvent *event)
{
    qDebug() << "Mouse enter";
//    resizeCell(MinimizeCellSize);
    state->changeCell(*this, MinimizeCellSize);
}

void Cell::leaveEvent(QEvent *event)
{
    qDebug() << "Mouse leave";
//    resizeCell(RealCellSize);
    state->changeCell(*this, RealCellSize);
}

void Cell::mousePressEvent(QMouseEvent *event)
{
    state->clickOn(*this);
}

void Cell::show()
{
    mGraphic.show();
}

void Cell::resizeCell(int toSize)
{
    auto pxm = mGraphic.pixmap();
    mGraphic.setPixmap(pxm->scaledToHeight(toSize));
}


