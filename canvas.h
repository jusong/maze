#ifndef CANVAS_H
#define CANVAS_H

#include "base.h"

class Canvas : public Base {
 public:
    Canvas(string _body = " ", int _frontcolor = 34, int _backcolor = 44);
    ~Canvas();
    void setBody(string _body);
    void setFrontColor(int _frontcolor);
    void setBackColor(int _backcolor);
    void setWidth(int _width);
    void setHeight(int _height);
    void setAnchor_x(int _anchor_x);
    void setAnchor_y(int _anchor_y);
    void print() const;
    
 private:
    string m_strBody;		//实体
    int m_iFrontColor;		//前端颜色
    int m_iBackColor;		//背景颜色
    int m_iWidth;			//宽度
    int m_iHeight;			//高度
    int m_iAnchor_x;		//锚点横坐标
    int m_iAnchor_y;		//锚点纵坐标
};

#endif
