#ifndef CANVAS_H
#define CANVAS_H

#include "base.h"

class Canvas : public Base {
 public:
    Canvas(string _body = " ", int _frontcolor = 34, int _backcolor = 44, int _width = 60, int _height = 20);
    void setBody(string _body);
    void setFrontColor(int _frontcolor);
    void setBackColor(int _backcolor);
    void setWidth(int _width);
    void setHeight(int _height);
    void setAnchor_x(int _anchor_x);
    void setAnchor_y(int _anchor_y);
    void addChild(void *);
    void deleteChild(void *);
    void print() const;
    
 private:
    int m_iAnchor_x;		//锚点横坐标
    int m_iAnchor_y;		//锚点纵坐标
};

#endif
