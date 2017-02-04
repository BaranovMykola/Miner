#ifndef GRIDFIELD_H
#define GRIDFIELD_H

#include <QWidget>
#include <QLayout>

#include "cell.h"

const int Width = 10;
const int Height = 10;

class GridField : public QWidget
{
    Q_OBJECT
public:
    explicit GridField(QWidget* parent = 0);
    QVBoxLayout *getField();
private:
    QVBoxLayout mField;
};

#endif // GRIDFIELD_H
