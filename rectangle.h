#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "rectilinearfigure.h"

class Rectangle : public RectilinearFigure
{
    QPointF pos1,pos2,pos3,pos4;
public:
    Rectangle(QPointF _pos1,QPointF _pos2,QPointF _pos3,QPointF _pos4);
    Rectangle(QPointF _pos1,QPointF _pos2);
};

#endif // RECTANGLE_H
