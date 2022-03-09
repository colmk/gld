#ifndef RECTILINEARFIGURE_H
#define RECTILINEARFIGURE_H

#include <QVector>
#include <QPainter>
#include <QListWidget>
#include "straightline.h"

class RectilinearFigure
{
protected:
    QVector<StraightLine> lines;
    QPointF center;
    QListWidget *loger = nullptr;
public:
    RectilinearFigure() = default;
    RectilinearFigure(const std::initializer_list<QPointF>& pos, decltype(loger) _loger = nullptr);
    void Rotate(const QPointF &rotCenterPos, const double& angle);
    void Move(const QPointF &offsetPos);
    virtual ~RectilinearFigure();
    virtual void paint(QPainter& painter);
};

#endif // RECTILINEARFIGURE_H
