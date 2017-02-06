#include "sun.h"

#include <QDebug>

Sun::Sun(GridField& field, QWidget *parent):
    AbstractCell(parent),
    mType(SunType::BasicSun),
    mField(field)
{
    updateGrpahic();
}

void Sun::updateGrpahic()
{
    AbstractCell::updateGrpahic(SunGraphicsFile.at(mType));
}

void Sun::setEnabled(bool enabled)
{
    if(enabled)
    {
        connect(this, SIGNAL(mouseHovered()), this, SLOT(slotAnimationOn()), Qt::UniqueConnection);
        connect(this, SIGNAL(mouseReleased()), this, SLOT(slotAnimaionOff()), Qt::UniqueConnection);
        connect(this, SIGNAL(mouseClickedMineButton()), this, SLOT(slotRestart()), Qt::UniqueConnection);
    }
    else
    {
        disconnect(this, SIGNAL(mouseHovered()), this, SLOT(slotAnimationOn()));
        disconnect(this, SIGNAL(mouseReleased()), this, SLOT(slotAnimaionOff()));
        disconnect(this, SIGNAL(mouseClickedMineButton()), this, SLOT(slotRestart()));
    }
}

void Sun::setImage(SunType type)
{
    mType = type;
    updateGrpahic();
}

void Sun::slotRestart()
{
    mField.resetGridField(10);
    mType = SunType::BasicSun;
    updateGrpahic();
    setEnabled(false);
}

//void Sun::slotRestart(GridField &field, const int count)
//{
////    field.resetGridField(count);
//}

void Sun::slotAnimationOn()
{
    resizeCell(SunAnimSize);
}

void Sun::slotAnimaionOff()
{
    resizeCell(SunSize);
    qDebug() <<"resized again";
}
