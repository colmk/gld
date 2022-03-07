#include "rectilinearfigure.h"
#include <iostream>

void RectilinearFigure::Move(const QPointF &offsetPos){
    if(loger){
        auto mdl_ptr = loger->model();
        mdl_ptr->insertColumn(0);
        // TODO: 日志
    }
    for(auto &iline:lines){
        iline.StraightLine::move(offsetPos);
    }
}

void RectilinearFigure::setLoger(decltype(loger)_loger)
{
    this->loger = _loger;
}


RectilinearFigure::~RectilinearFigure(){
    loger = nullptr;
}

void RectilinearFigure::paint(QPainter &painter)
{
    for(auto& iline: lines){
        painter.drawLine(iline.startPos,iline.endPos);
    }

}
