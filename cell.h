#ifndef CELL_H
#define CELL_H

#include <QLabel>

#include <QWidget>
#include <QString>

#include <map>
#include <memory>

#include "abstractcellstate.h"
#include "basiccellstate.h"
#include "abstractcell.h"

enum ImageType{Basic, Flag, Quastion, Empty, One, Two, Three, Four, Five, Six, Seven, Eight, Mine, Exploded};
const QString ResourcePrefix = ":/cells/resources/%1.png";
const std::map<ImageType, QString> GraphicsFile =
{
    std::make_pair(ImageType::Basic, ResourcePrefix.arg("basic_cell")),
    std::make_pair(ImageType::Empty, ResourcePrefix.arg("empty_cell")),
    std::make_pair(ImageType::One, ResourcePrefix.arg("cell_1")),
    std::make_pair(ImageType::Two, ResourcePrefix.arg("cell_2")),
    std::make_pair(ImageType::Three, ResourcePrefix.arg("cell_3")),
    std::make_pair(ImageType::Four, ResourcePrefix.arg("cell_4")),
    std::make_pair(ImageType::Five, ResourcePrefix.arg("cell_5")),
    std::make_pair(ImageType::Six, ResourcePrefix.arg("cell_6")),
    std::make_pair(ImageType::Seven, ResourcePrefix.arg("cell_7")),
    std::make_pair(ImageType::Eight, ResourcePrefix.arg("cell_8")),
    std::make_pair(ImageType::Flag, ResourcePrefix.arg("cell_f")),
    std::make_pair(ImageType::Mine, ResourcePrefix.arg("cell_m")),
    std::make_pair(ImageType::Quastion, ResourcePrefix.arg("cell_q")),
    std::make_pair(ImageType::Exploded, ResourcePrefix.arg("cell_m_e"))
};

const int RealCellSize = 30;
const int MinimizeCellSize = 28;

class Cell : public AbstractCell
{
    Q_OBJECT
    friend class BasicCellState;
    friend class GridField;
public:
    explicit Cell(QWidget *parent = 0);
    void setMine(bool mine);
    bool isMine()const;
    void open();
    void reset();
    void resetState();
    void changeToStepped();
signals:
    void mine();
    void stepped();
    void endKiss();
public slots:
    void slotStep();
    void slotFlag();
    void slotAnimationOn();
    void slotAnimationOff();
    void slotMouseClickReleased();
private:
    bool isEmpty();
    void updateGrpahic();
    void stepWithoutSignals();

    ImageType mTypeCell;
    bool mMine;
    std::unique_ptr<AbstractCellState> state;
    int mMineBeside;
};

#endif // CELL_H

