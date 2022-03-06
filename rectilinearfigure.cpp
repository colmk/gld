#include "rectilinearfigure.h"
#include <iostream>

void RectilinearFigure::Move(const QPointF &offsetPos){
    for(auto &iline:lines){
        iline.StraightLine::move(offsetPos);
    }
}


RectilinearFigure::~RectilinearFigure(){

}

void RectilinearFigure::paint(QPainter &painter)
{
    for(auto& iline: lines){
        painter.drawLine(iline.startPos,iline.endPos);
    }

}
