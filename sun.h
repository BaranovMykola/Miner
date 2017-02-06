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
    std::make_pair(SunType::BasicSun, SunResourcePrefix.arg("sun")),
    std::make_pair(SunType::ExplodedSun, SunResourcePrefix.arg("sun_e")),
    std::make_pair(SunType::Win, SunResourcePrefix.arg("sun_g")),
    std::make_pair(SunType::Kiss, SunResourcePrefix.arg("sun_k"))
};

class Sun : public AbstractCell
{
    Q_OBJECT
public:
    explicit Sun(GridField& field, QWidget* parent = 0);
    void updateGrpahic();
    void setEnabled(bool enabled);
    void setImage(SunType type);
public slots:
    void slotRestart();
//    void slotRestart(GridField& field, const int count);
    void slotAnimationOn();
    void slotAnimaionOff();
private:
    SunType mType;
    GridField& mField;
};

#endif // SUN_H
