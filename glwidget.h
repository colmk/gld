#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include "rectilinearfigure.h"
#include <QStandardItemModel>
#include <QDebug>
#include <QListWidget>
#include <mutex>
class GLWidget final: public QOpenGLWidget
{
    Q_OBJECT
public:
    enum class BuildState{
        None,
        Line,
        Triangle,
        Rectangle
    };
private:
    QStandardItemModel *qsim;
    QListWidget* loger = nullptr;
    std::mutex inputMtx;
    int needPosCnt = -1;             // 需要采集的点的数量
    std::vector<QPointF> inputTmp{}; // 创建图形时缓存的位置信息
    BuildState cs = BuildState::None;
    std::vector<RectilinearFigure> rectFigures;
public:
    GLWidget(QWidget *parent, QListWidget* lv = nullptr, QStandardItemModel* qsim = nullptr);
protected:
    void paintEvent(QPaintEvent *event)override;
    virtual void mousePressEvent(QMouseEvent *ev) override;
    virtual void mouseMoveEvent(QMouseEvent *ev) override;
    virtual void mouseReleaseEvent(QMouseEvent *ev) override;
public slots:
    void setState(GLWidget::BuildState newSt);
signals:
    void setneedposcntSignal(GLWidget::BuildState);
};

#endif // GLWIDGET_H
