#ifndef LINE_H
#define LINE_H

#include "rectilinearfigure.h"
#include <iostream>
class Line : public RectilinearFigure
{
    QPointF pos1,pos2;
public:
    Line(const QPointF& _pos1, const QPointF& _pos2):pos1(_pos1),pos2(_pos2){lines.push_back(StraightLine(pos1,pos2));};
};

#endif // LINE_H
