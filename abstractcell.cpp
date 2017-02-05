#include "abstractcell.h"

#include <QMouseEvent>
#include <QDebug>

AbstractCell::AbstractCell(QWidget *parent) : QWidget(parent)
{
    mGraphic.setParent(this);

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
    auto p = QPixmap(34,34);
    p.load(name);
    mGraphic.setPixmap(p);
//        auto g = this->geometry();
//        g.setWidth(34);
//        g.setHeight(34);
        this->setMaximumWidth(34);
        this->setMaximumHeight(34);
    this->setMinimumWidth(34);
    this->setMinimumHeight(34);
}

void AbstractCell::resizeCell(int toSize)
{
    auto pxm = mGraphic.pixmap();
    mGraphic.setPixmap(pxm->scaledToHeight(toSize));
}
