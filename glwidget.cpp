#include "glwidget.h"
#include <QPainter>
#include "line.h"
#include <QMouseEvent>
#include <mutex>
GLWidget::GLWidget(QWidget *parent):QOpenGLWidget(parent)
{
    setFixedSize(1121,571);
    setAutoFillBackground(false);
}

void GLWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;

    painter.begin(this);
    QBrush qb(QColor(0,0,0));
    QPen qpen;
    qpen.setWidth(1);
    painter.setPen(qpen);
    painter.setBackground(qb);
    painter.setRenderHint(QPainter::Antialiasing);
    for(auto &ifig:rectFigures){
        ifig.paint(painter);
    }
    painter.end();
}

void GLWidget::mousePressEvent(QMouseEvent *ev)
{

}

void GLWidget::mouseMoveEvent(QMouseEvent *ev)
{

}

void GLWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    std::lock_guard<std::mutex> lg(inputMtx);
    if(inputTmp.size() < needPosCnt){
        std::cout << "save Pos" << std::endl;
        inputTmp.push_back({static_cast<double>(ev->x()), static_cast<double>(ev->y())});
    }
    if(inputTmp.size() == needPosCnt){
        std::cout << "fin" << std::endl;
        switch(needPosCnt){
        case 2:         // 两点线段
            rectFigures.push_back(Line({inputTmp[0].toPoint()},{inputTmp[1].toPoint()}));
            // TODO: 改成可变参？工厂类？

            break;
        case 3:         // 三角形
            //TODO
            break;
        default:
            assert(false);
            break;
        }
        inputTmp.clear();
        needPosCnt = -1;        // 重置
        this->update();
    }

}

void GLWidget::setneedPosCnt(size_t newVal)
{
    std::lock_guard<std::mutex> lg(inputMtx);
    needPosCnt = newVal;
    inputTmp.clear();
}
