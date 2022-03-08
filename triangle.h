#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "rectilinearfigure.h"

class Triangle : public RectilinearFigure
{
    QPointF pos1,pos2,pos3;
public:
    Triangle(QPointF _pos1,QPointF _pos2,QPointF _pos3);
};

#endif // TRIANGLE_H
