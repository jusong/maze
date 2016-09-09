#ifndef BASE_H
#define BASE_H

#include <vector>
using namespace std;

class Base {
 public:
    Base(string _body, int _frontcolor, int _backcolor, int _width, int _height);
    ~Base();
    void setParent(Base &parent);
    void addChild(Base &child);
    void deleteChild(Base &child);
    void print() const;
    void setBody(string _body);
    void setFrontColor(int _frontcolor);
    void setBackColor(int _backcolor);
    void setWidth(int _width);
    void setHeight(int _height);
    void setAnchor_x(int _anchor_x);
    void setAnchor_y(int _anchor_y);
    
 protected:
    Base *m_pParent;
    vector<Base *> *m_pChilds;
    int m_iChildCount;
    
    string m_strBody;		//实体
    int m_iFrontColor;		//前端颜色
    int m_iBackColor;		//背景颜色
    int m_iWidth;			//宽度
    int m_iHeight;			//高度
    int m_iAnchor_x;		//锚点横坐标
    int m_iAnchor_y;		//锚点纵坐标
};

#endif
