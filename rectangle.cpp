#include "rectangle.h"
#include <iostream>
Rect::Rect(QPointF _pos1, QPointF _pos2, QPointF _pos3, QPointF _pos4 ,QStandardItemModel* _qsil , QListWidget* _loger)
    :RectilinearFigure(_loger,_qsil),
    pos1(_pos1), pos2(_pos2), pos3(_pos3),pos4(_pos4)
{
    loger = _loger;
    lines.push_back(StraightLine(pos1,pos2));
    lines.push_back(StraightLine(pos2,pos3));
    lines.push_back(StraightLine(pos3,pos4));
    lines.push_back(StraightLine(pos4,pos1));
    record("Create Rectangle : (" +
                   QString::number(pos1.x()) + "," + QString::number(pos1.y()) + ") (" +
                   QString::number(pos2.x()) + "," + QString::number(pos2.y())+ ") (" +
                   QString::number(pos3.x()) + "," + QString::number(pos3.y())+ ") (" +
                   QString::number(pos4.x()) + "," + QString::number(pos4.y())+ ")");

    auto items = qsim->findItems("Rectangle");
    assert(items.size() == 1);
    items.front()->appendRow(new QStandardItem(QString::number(id)));

}

Rect::Rect(QPointF _pos1, QPointF _pos2, QStandardItemModel* _qsil , QListWidget* _loger)
    :Rect::Rect(QPointF(_pos1.x(),_pos1.y()),QPointF(_pos1.x(),_pos2.y()),QPointF(_pos2.x(),_pos2.y()),QPointF(_pos2.x(),_pos1.y()),_qsil,_loger)
{
};
