#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "rectilinearfigure.h"

class Triangle : public RectilinearFigure
{
    QPointF pos1,pos2,pos3;
public:
    Triangle(QPointF _pos1,QPointF _pos2,QPointF _pos3):
        pos1(_pos1), pos2(_pos2), pos3(_pos3)
    {lines.push_back(StraightLine(pos1,pos2));lines.push_back(StraightLine(pos2,pos3));lines.push_back(StraightLine(pos1,pos3));};
};

#endif // TRIANGLE_H
