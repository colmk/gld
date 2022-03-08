#include "line.h"

Line::Line(const QPointF &_pos1, const QPointF &_pos2)
    :pos1(_pos1),pos2(_pos2)
{
    lines.push_back(StraightLine(pos1,pos2));
}
