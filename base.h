#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>
using namespace std;

class Base {
 public:
    Base();
    Base(int _width, int _height);
    Base(Base &base);
    ~Base();
    
    void setBody(string _body);
    void setColor(int _color);
    void setWidth(int _width);
    void setHeight(int _height);
    void setAnch_x(int _anch_x);
    void setAnch_y(int _anch_y);
    virtual void setParent(Base *parent);
    virtual void addChild(Base *child);
    virtual void deleteChild(Base *child);
    virtual bool isParent(Base *parent);
    virtual bool isChild(Base *child);

    string getBody() const;
    int getColor() const;
    int getWidth() const;
    int getHeight() const;
    int getAnch_x() const;
    int getAnch_y() const;
    Base* getParent() const;
    vector<Base *>* getChilds() const;
    
    virtual void printSelf() const;
    virtual void print(bool refreshBrother = true) const;
    
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
