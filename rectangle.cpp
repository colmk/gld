#include "rectangle.h"
#include <iostream>
Rectangle::Rectangle(QPointF _pos1, QPointF _pos2, QPointF _pos3, QPointF _pos4, QListWidget* _loger):
    pos1(_pos1), pos2(_pos2), pos3(_pos3),pos4(_pos4)
{
    loger = _loger;
    lines.push_back(StraightLine(pos1,pos2));
    lines.push_back(StraightLine(pos2,pos3));
    lines.push_back(StraightLine(pos3,pos4));
    lines.push_back(StraightLine(pos4,pos1));
    if(loger)
    loger->addItem("Create Rectangle : (" +
                   QString::number(pos1.x()) + "," + QString::number(pos1.y()) + ") (" +
                   QString::number(pos2.x()) + "," + QString::number(pos2.y())+ ") (" +
                   QString::number(pos3.x()) + "," + QString::number(pos3.y())+ ") (" +
                   QString::number(pos4.x()) + "," + QString::number(pos4.y())+ ")");
}

Rectangle::Rectangle(QPointF _pos1, QPointF _pos2, QListWidget* _loger):
    pos1(_pos1.x(),_pos1.y()),pos2(_pos1.x(),_pos2.y()),pos3(_pos2.x(),_pos2.y()),pos4(_pos2.x(),_pos1.y())
{
    loger = _loger;
    lines.push_back(StraightLine(pos1,pos2));
    lines.push_back(StraightLine(pos2,pos3));
    lines.push_back(StraightLine(pos3,pos4));
    lines.push_back(StraightLine(pos4,pos1));
    if(loger)
        loger->addItem("Create Rectangle : (" +
                       QString::number(pos1.x()) + "," + QString::number(pos1.y()) + ") (" +
                       QString::number(pos2.x()) + "," + QString::number(pos2.y())+ ") (" +
                       QString::number(pos3.x()) + "," + QString::number(pos3.y())+ ") (" +
                       QString::number(pos4.x()) + "," + QString::number(pos4.y())+ ")");
};
