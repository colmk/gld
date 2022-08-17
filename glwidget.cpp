#include "glwidget.h"
#include <QPainter>
#include "line.h"
#include "triangle.h"
#include "rectangle.h"
#include <QMouseEvent>
#include <mutex>
GLWidget::GLWidget(QWidget *parent, QListWidget* lv, QStandardItemModel* qsim)
    :QOpenGLWidget(parent)
    ,qsim(qsim)
    ,loger(lv)
{
    setAutoFillBackground(false);
    connect(this, &GLWidget::setneedposcntSignal, this, &GLWidget::setState);
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

void GLWidget::initializeGL()
{

     QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
     f->glClearColor(.99f, 0.99f, 0.99f, 0.0f);
}

void GLWidget::resizeGL(int w, int h)
{
}

void GLWidget::paintGL()
{

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
        qDebug("save Pos");
        inputTmp.push_back({static_cast<double>(ev->x()), static_cast<double>(ev->y())});
    }
    if(inputTmp.size() == needPosCnt){  // 创建完成
        std::cout << "fin" << std::endl;
        switch(cs){
        case BuildState::Line :         // 线段
            rectFigures.push_back(Line({inputTmp[0].toPoint()},{inputTmp[1].toPoint()},qsim,loger));
            break;
        case BuildState::Triangle :     // 三角形
            rectFigures.push_back(Triangle(inputTmp[0],inputTmp[1],inputTmp[2],qsim, loger));
            break;
        case BuildState::Rectangle:
            rectFigures.push_back( Rect(inputTmp[0],inputTmp[1],qsim, loger));
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

void GLWidget::setState(BuildState newVal)
{
    std::lock_guard<std::mutex> lg(inputMtx);
    cs = newVal;
    switch(newVal){
    case BuildState::Line:
        needPosCnt = 2;
        break;
    case BuildState::Triangle:
        needPosCnt = 3;
        break;
    case BuildState::Rectangle:
        needPosCnt = 2;
        break;
    default:
    case BuildState::None:
        needPosCnt = -1;
        cs = BuildState::None;
        break;
    }
    inputTmp.clear();
}
