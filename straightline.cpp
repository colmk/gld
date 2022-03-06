#include "straightline.h"

StraightLine::StraightLine(const QPointF &_startPos, const QPointF &_endPos)
{
    startPos = _startPos;
    endPos = _endPos;
}


void StraightLine::move(const QPointF &_offsetPos){
    startPos -= _offsetPos;
    endPos -= _offsetPos;
}
