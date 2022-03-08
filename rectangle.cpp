#include "rectangle.h"
#include <iostream>
Rectangle::Rectangle(QPointF _pos1, QPointF _pos2, QPointF _pos3, QPointF _pos4):
    pos1(_pos1), pos2(_pos2), pos3(_pos3),pos4(_pos4)
{
    lines.push_back(StraightLine(pos1,pos2));
    lines.push_back(StraightLine(pos2,pos3));
    lines.push_back(StraightLine(pos3,pos4));
    lines.push_back(StraightLine(pos4,pos1));
}

Rectangle::Rectangle(QPointF _pos1, QPointF _pos2):pos1(_pos1.x(),_pos1.y()),pos2(_pos1.x(),_pos2.y()),pos3(_pos2.x(),_pos2.y()),pos4(_pos2.x(),_pos1.y())
{
    lines.push_back(StraightLine(pos1,pos2));
    lines.push_back(StraightLine(pos2,pos3));
    lines.push_back(StraightLine(pos3,pos4));
    lines.push_back(StraightLine(pos4,pos1));
};
