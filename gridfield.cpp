#include "gridfield.h"

GridField::GridField(QWidget *parent):
    QWidget(parent)
{
    cells.resize(Width);
    for(int i = 0;i<Width;++i)
    {
        QHBoxLayout* hbox = new QHBoxLayout;
        for(int j = 0;j<Height;++j)
        {
            auto p = new Cell(this);
            cells[j].push_back(p);
            hbox->addWidget(p);

        }
        mField.addLayout(hbox);
    }
}

QVBoxLayout *GridField::getField()
{
    return &mField;
}

