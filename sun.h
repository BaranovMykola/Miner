#ifndef SUN_H
#define SUN_H

#include "abstractcell.h"
#include "gridfield.h"

const int SunSize = 34;
const int SunAnimSize = 32;

enum SunType{BasicSun, ExplodedSun, Win, Kiss};
const QString SunResourcePrefix = ":/sun/resources/%1.png";
const std::map<SunType, QString> SunGraphicsFile =
{
    std::make_pair(SunType::BasicSun, ResourcePrefix.arg("sun")),
    std::make_pair(SunType::ExplodedSun, ResourcePrefix.arg("sun_e")),
    std::make_pair(SunType::Win, ResourcePrefix.arg("sun_g")),
    std::make_pair(SunType::Kiss, ResourcePrefix.arg("sun_k"))
};

class Sun : public AbstractCell
{
public:
    explicit Sun(QWidget* parent = 0);
    void updateGrpahic();
public slots:
    void slotRestart(GridField& field, const int count);
    void slotAnimationOn();
    void slotAnimaionOff();
private:
    SunType mType;
};

#endif // SUN_H
