#ifndef RECTILINEARFIGURE_H
#define RECTILINEARFIGURE_H

#include <QVector>
#include <QPainter>
#include "straightline.h"

class RectilinearFigure
{
protected:
    QVector<StraightLine> lines;
    QPointF center;
public:
    RectilinearFigure() = default;
    RectilinearFigure(const std::initializer_list<QPointF>& pos);
    void Rotate(const QPointF &rotCenterPos, const double& angle);
    void Move(const QPointF &offsetPos);
    virtual ~RectilinearFigure();
    virtual void paint(QPainter& painter);
};

#endif // RECTILINEARFIGURE_H
