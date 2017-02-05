#include "sun.h"

#include <QDebug>

Sun::Sun(QWidget *parent):
    AbstractCell(parent),
    mType(SunType::BasicSun)
{
    updateGrpahic();
    connect(this, SIGNAL(mouseHovered()), this, SLOT(slotAnimationOn()), Qt::UniqueConnection);
    connect(this, SIGNAL(mouseReleased()), this, SLOT(slotAnimaionOff()), Qt::UniqueConnection);
}

void Sun::updateGrpahic()
{
    AbstractCell::updateGrpahic(SunGraphicsFile.at(mType));
}

void Sun::slotRestart(GridField &field, const int count)
{
    field.resetGridField(count);
}

void Sun::slotAnimationOn()
{
    resizeCell(SunAnimSize);
}

void Sun::slotAnimaionOff()
{
    resizeCell(SunSize);
    qDebug() <<"resized again";
}
