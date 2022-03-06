#ifndef STRAIGHTLINE_H
#define STRAIGHTLINE_H

#include <QPointF>

struct StraightLine
{
    QPointF startPos;
    QPointF endPos;
    StraightLine& operator=(StraightLine& _other);
    StraightLine(const QPointF &_startPos, const QPointF &_endPos);
    void move(const QPointF &_offsetPos);
    void rotate(const double& _angle);
};

#endif // STRAIGHTLINE_H
