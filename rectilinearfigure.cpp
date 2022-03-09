#include "rectilinearfigure.h"
#include <iostream>

void RectilinearFigure::Move(const QPointF &offsetPos){
    if(loger){
        loger->addItem("MOVE: offset " + QString::number(offsetPos.x()) + " " + QString::number(offsetPos.y()));
        // TODO: 日志
    }
    for(auto &iline:lines){
        iline.StraightLine::move(offsetPos);
    }
}

RectilinearFigure::~RectilinearFigure(){
    loger = nullptr;
}

void RectilinearFigure::paint(QPainter &painter)
{
    std::cout << __func__ << std::endl;
    std::cout << lines.size() << std::endl;
    for(auto& iline: lines){
        painter.drawLine(iline.startPos,iline.endPos);
    }

}
