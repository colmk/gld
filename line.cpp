#include "line.h"

Line::Line(const QPointF &_pos1, const QPointF &_pos2, QListWidget* _loger)
    :pos1(_pos1),pos2(_pos2)
{
    loger = _loger;
    lines.push_back(StraightLine(pos1,pos2));
    if(loger)
    loger->addItem("Create Line : (" +
                   QString::number(pos1.x()) + "," + QString::number(pos1.y()) + ") (" +
                   QString::number(pos2.x()) + "," + QString::number(pos2.y())+")");
}
