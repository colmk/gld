#include "line.h"

Line::Line(const QPointF &_pos1, const QPointF &_pos2,QStandardItemModel* _qsil , QListWidget* _loger)
    :RectilinearFigure(_loger,_qsil)
      ,pos1(_pos1)
    ,pos2(_pos2)
{
    loger = _loger;
    lines.push_back(StraightLine(pos1,pos2));
    record("Create Line : (" +
                   QString::number(pos1.x()) + "," + QString::number(pos1.y()) + ") (" +
                   QString::number(pos2.x()) + "," + QString::number(pos2.y())+")");
    auto items = qsim->findItems("Line");
    assert(items.size() == 1);
    items.front()->appendRow(new QStandardItem(QString::number(id)));
}
