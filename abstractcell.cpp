#include "abstractcell.h"

AbstractCell::AbstractCell(QWidget *parent) : QWidget(parent)
{

}

void AbstractCell::enterEvent(QEvent *event)
{
    emit mouseHovered();
}

void AbstractCell::leaveEvent(QEvent *event)
{
    emit mouseReleased();
}

void AbstractCell::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit mouseClickedMineButton();
    }
    else
    {
        emit mouseClicked();
    }
}

void AbstractCell::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit mouseClickReleased();
    }
}

void AbstractCell::updateGrpahic(const QString &name)
{
    mGraphic.setPixmap(QPixmap(name));
}

void AbstractCell::resizeCell(int toSize)
{
    auto pxm = mGraphic.pixmap();
    mGraphic.setPixmap(pxm->scaledToHeight(toSize));
}
