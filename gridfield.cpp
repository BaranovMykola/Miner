#include "gridfield.h"

GridField::GridField(QWidget *parent):
    QWidget(parent)
{
    for(int i = 0;i<Width;++i)
    {
        QHBoxLayout* hbox = new QHBoxLayout;
        for(int j = 0;j<Height;++j)
        {
            auto p = new Cell(this);
            hbox->addWidget(p);
            p->show();
        }
        mField.addLayout(hbox);
    }
}

QVBoxLayout *GridField::getField()
{
    return &mField;
}

