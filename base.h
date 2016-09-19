#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>
using namespace std;

class Base {
 public:
    Base();
    Base(const int _width, const int _height);
    Base(const Base &_base);
    ~Base();
    
    void setBody(const string _body);
    void setColor(const int _color);
    void setWidth(const int _width);
    void setHeight(const int _height);
    void setAnch_x(const int _anch_x);
    void setAnch_y(const int _anch_y);
    void setId(const int _id);
    void setTag(const string _tag);
    void setHidden(bool _hidden);
    
    virtual void setParent(Base *parent);
    virtual void addChild(Base *child);
    virtual void deleteChild(Base *child);
    virtual bool isParent(const Base *parent);
    virtual bool isChild(const Base *child);

    string getBody() const;
    int getColor() const;
    int getWidth() const;
    int getHeight() const;
    int getAnch_x() const;
    int getAnch_y() const;
    int getId() const;
    string getTag() const;
    virtual Base* getParent() const;
    virtual vector<Base *>* getChilds() const;
    
    virtual void printSelf() const;
    virtual void print(bool refreshBrother = true) const;

    virtual Base *findChildByTag(const string _tag) const ;
    virtual Base *findChildById(const int _id) const ;
    virtual Base &operator=(const Base &_base);
    
 protected:
    int m_iId;					//控件ID
    string m_strTag;			//控件TAG
    Base *m_pParent;			//父对象
    vector<Base *> *m_pChilds;	//子对象集合
    
    string m_strBody;		//实体
    int m_iColor;			//颜色
    int m_iWidth;			//宽度
    int m_iHeight;			//高度
    int m_iAnch_x;			//锚点横坐标
    int m_iAnch_y;			//锚点纵坐标

    bool m_bHidden;			//隐藏
};

#endif
