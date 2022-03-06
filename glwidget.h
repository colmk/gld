#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include "rectilinearfigure.h"
#include <QDebug>
#include <mutex>
class GLWidget final: public QOpenGLWidget
{
    Q_OBJECT
    /*enum input_state{
        NONE,           // 当前不需要缓存， needPosCnt应当为0
        INPUTTING        // 当前正在进行缓存，needPosCnt > inputTmp.size()
    };*/
    std::mutex inputMtx;
    int needPosCnt = 2;             //位置信息数量
    std::vector<QPointF> inputTmp; // 创建图形时缓存的位置信息
public:
    GLWidget(QWidget *parent);

protected:

    void paintEvent(QPaintEvent *event) override;
    std::vector<RectilinearFigure> rectFigures;
    virtual void mousePressEvent(QMouseEvent *ev) override;
    virtual void mouseMoveEvent(QMouseEvent *ev) override;
    virtual void mouseReleaseEvent(QMouseEvent *ev) override;
public slots:
    void setneedPosCnt(size_t);
signals:
    void setneedposcntSignal(int);//TODO:从btn的clicked函数发送`emit`
};

#endif // GLWIDGET_H
