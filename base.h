#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>
using namespace std;

class Base {
 public:
    Base(int _width = 60, int _height = 20);
    ~Base();
    void setBody(string _body);
    void setColor(int _color);
    void setWidth(int _width);
    void setHeight(int _height);
    void setAnch_x(int _anch_x);
    void setAnch_y(int _anch_y);

    int getWidth() const;
    int getHeight() const;
    int getAnch_x() const;
    int getAnch_y() const;
    virtual void printSelf() const;
    virtual void print() const;
    vector<Base *>* getChilds() const;
    
    virtual void setParent(Base *parent);
    virtual void addChild(Base *child);
    virtual void deleteChild(Base *child);
    
 protected:
    Base *m_pParent;
    vector<Base *> *m_pChilds;
    
    string m_strBody;		//实体
    int m_iColor;			//颜色
    int m_iWidth;			//宽度
    int m_iHeight;			//高度
    int m_iAnch_x;			//锚点横坐标
    int m_iAnch_y;			//锚点纵坐标
};

#endif
