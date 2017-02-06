#include "gridfield.h"

#include <QDebug>
#include <QSignalMapper>

#include <ctime>
#include <iterator>
//#include <QCoreApplication>

#include "steppedcellstate.h"

GridField::GridField(QWidget *parent):
    QWidget(parent)
{
    QSignalMapper* mapper = new QSignalMapper(this);
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
    int w = 0;
    int h = 0;
    for(auto i : cells)
    {
        for(auto j : i)
        {
            QObject::connect(j, &Cell::stepped, [this, w, h](){this->slotStepOn(w,h);});
            QObject::connect(j, SIGNAL(mine()), this, SLOT(slotMine()), Qt::UniqueConnection);
            QObject::connect(j, SIGNAL(endKiss()), this, SLOT(slotClickReleased()), Qt::UniqueConnection);
            ++h;
        }
        h = 0;
        ++w;
    }
    srand(time(0));
}

QVBoxLayout *GridField::getField()
{
    return &mField;
}

void GridField::setMine(int count)
{
    for(int i=0;i<count;++i)
    {
        int w;
        int h;
        do
        {
            w = rand()%Width;
            h = rand()%Height;
        }
        while(cells[w][h]->isMine());
        cells[w][h]->setMine(true);
        updateBesideCells(w,h);

    }
}

void GridField::updateBesideCells(int w, int h)
{
    int _w = w-1;
    for(;_w <= w+1;++_w)
    {
        int _h = h-1;
        for(;_h<=h+1;++_h)
        {
            if(isCorrect(_w, _h) &&
                    !(_w == w && _h == h))
            {
//                qDebug() << "_w: " << _w << " _h: " << _h << "cells: " << cells[_w][_h];
                ++(cells[_w][_h]->mMineBeside);
            }
        }
    }
}

void GridField::resetCells()
{
    for(auto i : cells)
    {
        for(auto j : i)
        {
            j->reset();
        }
    }
}

void GridField::resetGridField(int minesCount)
{
    resetCells();
    setMine(minesCount);
    for(auto i : cells)
    {
        for(auto j : i)
        {
            QObject::connect(j, SIGNAL(endKiss()), this, SLOT(slotClickReleased()), Qt::UniqueConnection);
        }
    }
}

void GridField::slotStepOn(int w, int h)
{
    try
    {
        if(isCorrect(w,h))
        {
            emit mouseClicked();
            qDebug() << "Opening w: " << w << " h: " << h
                     << " mMineBeside: " << cells[w][h]->mMineBeside
                     << " isMine(): " << cells[w][h]->isMine()
                     << " Basic: " << (cells[w][h]->mTypeCell == ImageType::Basic);
            if(cells[w][h]->mMineBeside == 0 && !cells[w][h]->isMine() && cells[w][h]->mTypeCell == ImageType::Basic)
            {
                qDebug() << "\t Open...";
                recursiveProxy(w,h);
            }
            else
            {
                qDebug() << "\t Not opening...";
            }
        }
        else
        {
            qDebug() << "Incorrect w: " << w << " h: " << h;
        }
    }
    catch(...)
    {
        qDebug() << "[ERROR] UNHANDLED EXCEPTION";
    }
}

void GridField::slotMine()
{
    for(auto i : cells)
    {
        for(auto j : i)
        {
            j->state.reset();
            j->state = std::make_unique<SteppedCellState>(SteppedCellState());
            QObject::disconnect(j, SIGNAL(endKiss()), this, SLOT(slotClickReleased()));
            if(!j->isMine())
            {
                j->open();
            }

            else
            {
                j->mTypeCell = ImageType::Exploded;
                j->updateGrpahic();
            }
        }
    }
    emit loose();
}

void GridField::slotClickReleased()
{
    emit mouseCLickReleased();
}

void GridField::recursiveOpen(int w, int h)
{
    cells[w][h]->stepWithoutSignals();
    if(isCorrect(w,h+1) && cells[w][h+1]->mTypeCell == ImageType::Basic && cells[w][h]->mTypeCell == ImageType::Empty)
    {
        recursiveOpen(w, h+1);
    }
    if(isCorrect(w,h-1) && cells[w][h-1]->mTypeCell == ImageType::Basic && cells[w][h]->mTypeCell == ImageType::Empty)
    {
        recursiveOpen(w, h-1);
    }
    if(isCorrect(w+1,h) && cells[w+1][h]->mTypeCell == ImageType::Basic && cells[w][h]->mTypeCell == ImageType::Empty)
    {
        recursiveOpen(w+1, h);
    }
    if(isCorrect(w-1,h) && cells[w-1][h]->mTypeCell == ImageType::Basic && cells[w][h]->mTypeCell == ImageType::Empty)
    {
        recursiveOpen(w-1, h);
    }
}

void GridField::recursiveProxy(int w, int h)
{
    if(isCorrect(w,h+1) && cells[w][h+1]->mTypeCell == ImageType::Basic)
    {
        recursiveOpen(w, h+1);
    }
    if(isCorrect(w,h-1) && cells[w][h-1]->mTypeCell == ImageType::Basic)
    {
        recursiveOpen(w, h-1);
    }
    if(isCorrect(w+1,h) && cells[w+1][h]->mTypeCell == ImageType::Basic)
    {
        recursiveOpen(w, h+1);
    }
    if(isCorrect(w-1,h) && cells[w-1][h]->mTypeCell == ImageType::Basic)
    {
        recursiveOpen(w-1, h);
    }
}

bool GridField::isCorrect(int _w, int _h)
{
    return _w < Width && _h < Height && _w >= 0 && _h >= 0;
}

std::pair<int, int> GridField::getPosition(Cell *_cell)
{
    std::vector<std::vector<Cell*>>::iterator widthIterator;
    for(;widthIterator != cells.end();++widthIterator)
    {
        auto it = std::find(widthIterator->begin(), widthIterator->end(), _cell);
        if(it != widthIterator->end())
        {
            return std::make_pair(std::distance(cells.begin(), widthIterator),
                                    std::distance(widthIterator->begin(), it));
        }
    }
    throw "NotFound";
}

