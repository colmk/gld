#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "rectilinearfigure.h"

class Rect : public RectilinearFigure
{
    QPointF pos1,pos2,pos3,pos4;
public:
    Rect(QPointF _pos1,QPointF _pos2,QPointF _pos3,QPointF _pos4, QStandardItemModel* _qsil =nullptr , QListWidget* _loger =nullptr);
    Rect(QPointF _pos1,QPointF _pos2, QStandardItemModel* _qsil =nullptr , QListWidget* _loger =nullptr);
};

#endif // RECTANGLE_H
