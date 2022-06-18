#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include "rectilinearfigure.h"
#include <QStandardItemModel>
#include <QDebug>
#include <QListWidget>
#include <mutex>
#include <QOpenGLFunctions>
class GLWidget final: public QOpenGLWidget, protected QOpenGLFunctions
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
    std::size_t needPosCnt = -1;             // 需要采集的点的数量
    std::vector<QPointF> inputTmp{}; // 创建图形时缓存的位置信息
    BuildState cs = BuildState::None;
    std::vector<RectilinearFigure> rectFigures;

public:
    GLWidget(QWidget *parent, QListWidget* lv = nullptr, QStandardItemModel* qsim = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    virtual void mousePressEvent(QMouseEvent *ev) override;
    virtual void mouseMoveEvent(QMouseEvent *ev) override;
    virtual void mouseReleaseEvent(QMouseEvent *ev) override;
public slots:
    void setState(GLWidget::BuildState newSt);
signals:
    void setneedposcntSignal(GLWidget::BuildState);
};

#endif // GLWIDGET_H
