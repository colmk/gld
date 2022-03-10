#include "triangle.h"

Triangle::Triangle(QPointF _pos1,QPointF _pos2,QPointF _pos3, QListWidget * _loger):
    pos1(_pos1), pos2(_pos2), pos3(_pos3)
{
    loger = _loger;
    lines.push_back(StraightLine(pos1,pos2));
    lines.push_back(StraightLine(pos2,pos3));
    lines.push_back(StraightLine(pos1,pos3));
    record("Create Triangle : (" +
                   QString::number(pos1.x()) + "," + QString::number(pos1.y()) + ") (" +
                   QString::number(pos2.x()) + "," + QString::number(pos2.y())+") (" +
                   QString::number(pos3.x()) + "," + QString::number(pos3.y()) + ")");
};
