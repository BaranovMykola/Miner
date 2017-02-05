#include "sun.h"

Sun::Sun(QWidget *parent):
    AbstractCell(parent)
{

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
}
