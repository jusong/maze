#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>
using namespace std;

class Base {
 public:
    Base(string _body = " ", int _frontcolor = 34, int _backcolor = 44, int _width = 60, int _height = 20);
    ~Base();
    void setBody(string _body);
    void setFrontColor(int _frontcolor);
    void setBackColor(int _backcolor);
    void setWidth(int _width);
    void setHeight(int _height);
    void setAnch_x(int _anch_x);
    void setAnch_y(int _anch_y);
    void setRelatAnch_x(int _relat_anch_x);
    void setRelatAnch_y(int _relat_anch_y);
    void print() const;
    
    void setParent(Base &parent);
    void addChild(Base &child);
    void deleteChild(Base &child);
    
 protected:
    Base *m_pParent;
    vector<Base *> *m_pChilds;
    
    string m_strBody;		//实体
    int m_iFrontColor;		//前端颜色
    int m_iBackColor;		//背景颜色
    int m_iWidth;			//宽度
    int m_iHeight;			//高度
    int m_iAnch_x;		//锚点横坐标
    int m_iAnch_y;		//锚点纵坐标
    int m_iRelatAnch_x;		//相对锚点横坐标
    int m_iRelatAnch_y;		//相对锚点纵坐标
};

#endif
