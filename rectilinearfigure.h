#ifndef RECTILINEARFIGURE_H
#define RECTILINEARFIGURE_H

#include <QVector>
#include <QPainter>
#include <QListView>
#include "straightline.h"

class RectilinearFigure
{
protected:
    QVector<StraightLine> lines;
    QPointF center;
    QListView *loger = nullptr;
public:
    RectilinearFigure() = default;
    RectilinearFigure(const std::initializer_list<QPointF>& pos);
    void Rotate(const QPointF &rotCenterPos, const double& angle);
    void Move(const QPointF &offsetPos);
    void setLoger(decltype(loger) _loger);
    virtual ~RectilinearFigure();
    virtual void paint(QPainter& painter);
};

#endif // RECTILINEARFIGURE_H
