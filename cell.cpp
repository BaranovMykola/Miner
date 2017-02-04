#include "cell.h"

#include <QDebug>

Cell::Cell(QWidget *parent) : QWidget(parent)
{
    mGraphic.setParent(this);
    mGraphic.setPixmap(QPixmap(GraphicsFile.at(ImageType::Seven)));
}

void Cell::show()
{
    mGraphic.show();
}

