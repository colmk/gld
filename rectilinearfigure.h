#ifndef RECTILINEARFIGURE_H
#define RECTILINEARFIGURE_H

#include <QVector>
#include <QPainter>
#include <QListWidget>
#include "straightline.h"

class RectilinearFigure
{
private:
    uint32_t _id;
protected:
    const uint32_t& id = _id;
    QVector<StraightLine> lines;
    QPointF center;
    QListWidget *loger = nullptr;
    void record(const QString& logHead);
public:
    RectilinearFigure();
    void Rotate(const QPointF &rotCenterPos, const double& angle);
    void Move(const QPointF &offsetPos);
    virtual ~RectilinearFigure();
    virtual void paint(QPainter& painter);
};

#endif // RECTILINEARFIGURE_H
