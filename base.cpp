#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <time.h>

#include "base.h"
#include "terminal.h"

using namespace std;

Base::Base() {
    Terminal::getWs(m_iWidth, m_iHeight);
    m_iId = 0;
    m_strTag = "";
    m_strBody = " ";
    m_iColor = 0;
    m_iAnch_x = m_iAnch_y = 0;
    m_pParent = NULL;
    m_pChilds = new vector<Base *>;
}

Base::Base(const int _width, const int _height) {
    m_iId = 0;
    m_strTag = "";
    m_iWidth = _width;
    m_iHeight = _height;
    m_strBody = " ";
    m_iColor = 0;
    m_iAnch_x = m_iAnch_y = 0;
    m_pParent = NULL;
    m_pChilds = new vector<Base *>;
}

Base::Base(const Base &_base) {
    m_iId = _base.getId();
    m_strTag = _base.getTag();
    m_iWidth = _base.getWidth();
    m_iHeight = _base.getHeight();
    m_strBody = _base.getBody();
    m_iColor = _base.getColor();
    m_iAnch_x = _base.getAnch_x();
    m_iAnch_y = _base.getAnch_y();
    m_pParent = _base.getParent();
    /* 当前对象设置为父对象的子 */
    if (m_pParent) {
        m_pParent->addChild(this);
    }
    m_pChilds = new vector<Base *>;
}

Base::~Base() {
    delete m_pChilds;
    m_pChilds = NULL;
}

void Base::setBody(const string _body) {
    m_strBody = _body;
}

void Base::setColor(const int _color) {
    m_iColor = _color;
}

void Base::setWidth(const int _width) {
    m_iWidth = _width;
}

void Base::setHeight(const int _height) {
    m_iHeight = _height;
}

void Base::setAnch_x(const int _anch_x) {
    m_iAnch_x = _anch_x;
}

void Base::setAnch_y(const int _anch_y) {
    m_iAnch_y = _anch_y;
}

void Base::setId(const int _id) {
    m_iId = _id;
}

void Base::setTag(const string _tag) {
    m_strTag = _tag;
}

void Base::setParent(Base *parent) {
    if (!isParent(parent)) {
        /* 从现有父对象中删除当前对象 */
        if (m_pParent) {
            m_pParent->deleteChild(this);
        }
        
        m_pParent = parent;
        
        /* 当前对象设置为父对象的子 */
        if (m_pParent) {
            m_pParent->addChild(this);
        }
    }
}

void Base::addChild(Base *child) {
    if (child && !isChild(child)) {
        m_pChilds->push_back(child);
        child->setParent(this);
    }
}

void Base::deleteChild(Base *child) {
    if (child) {
        vector<Base *>::iterator iter;
        iter = find(m_pChilds->begin(), m_pChilds->end(), child);
        if (iter != m_pChilds->end()) {
            m_pChilds->erase(iter);
        }
    }
}

bool Base::isParent(const Base *parent) {
    return m_pParent == parent;
}

bool Base::isChild(const Base *child) {
    if (!child) {
        return false;
    }
    vector<Base *>::iterator iter;
    iter = find(m_pChilds->begin(), m_pChilds->end(), child);
    return iter != m_pChilds->end();
}

string Base::getBody() const {
    return m_strBody;
}

int Base::getColor() const {
    return m_iColor;
}

int Base::getWidth() const {
    if (m_iWidth > 0) {
        return m_iWidth;
    } else if (m_pParent) {
        return m_pParent->getWidth() + m_iWidth;
    } else {
        return abs(m_iWidth);
    }
}

int Base::getHeight() const {
    if (m_iHeight > 0) {
        return m_iHeight;
    } else if (m_pParent) {
        return m_pParent->getHeight() + m_iHeight;
    } else {
        return abs(m_iHeight);
    }
}

//获取真实锚点横坐标
int Base::getAnch_x() const {
    /* 若设置了父类，当前锚点为相对于父类的锚点，否则为相对于（0,0）的锚点 */
    if (m_pParent) {
        return m_pParent->getAnch_x() + ((m_iAnch_x >= 0) ? m_iAnch_x : (m_pParent->getWidth() + m_iAnch_x));
    } else {
        return abs(m_iAnch_x);
    }
}

//获取真实锚点纵坐标
int Base::getAnch_y() const {
    /* 若设置了父类，当前锚点为相对于父类的锚点，否则为相对于（0,0）的锚点 */
    if (m_pParent) {
       	return m_pParent->getAnch_y() + ((m_iAnch_y >= 0) ? m_iAnch_y : (m_pParent->getHeight() + m_iAnch_y));
    } else {
        return abs(m_iAnch_y);
    }
}

int Base::getId() const {
    return m_iId;
}

string Base::getTag() const {
    return m_strTag;
}

Base* Base::getParent() const {
    return m_pParent;
}

vector<Base *>* Base::getChilds() const {
    return m_pChilds;
}

void Base::printSelf() const {
    int width = getWidth();
    int height = getHeight();
    
    /* 画背景 */
    string line;
    for (int i = 0; i < width; i++) {
        line += m_strBody;
    }
    int anchX = getAnch_x();
    int anchY = getAnch_y();
    for (int i = 0; i < height; i++) {
        Terminal::gotoPoint(anchX, anchY + i);
        Terminal::colorPrint(line, m_iColor);
    }
}

void Base::print(bool refreshBrother) const {
    /* 一级画布，清屏刷新 */
    if (!m_pParent) {
        /* 清屏 */
        Terminal::cleanScreen();
    }

    /* 画当前画布 */
    printSelf();
    
    /* 同级右支画布刷新 */
    if (refreshBrother && m_pParent) {
        int flag = 0;
        vector<Base *> *childs = m_pParent->getChilds();
        for (auto i : *childs) {
            if (flag) {
                i->print(false);
            } else if (i == this) {
                flag = 1;
            }
        }
    }

    /* 刷新子级画布 */
    for (auto i : *m_pChilds) {
        i->print(false);
    }
    
    /* 刷新输出缓存 */
    cout.flush();
}

Base* Base::findChildByTag(const string _tag) const {
    if (m_pChilds) {
        for(auto i : *m_pChilds) {
            if (i->getTag() == _tag) {
                return i;
            }
        }
    }
    return NULL;
}

Base* Base::findChildById(const int _id) const {
    if (m_pChilds) {
        for(auto i : *m_pChilds) {
            if (i->getId() == _id) {
                return i;
            }
        }
    }
    return NULL;
}

Base& Base::operator=(const Base &_base) {
    m_iId = _base.getId();
    m_strTag = _base.getTag();
    m_iWidth = _base.getWidth();
    m_iHeight = _base.getHeight();
    m_strBody = _base.getBody();
    m_iColor = _base.getColor();
    m_iAnch_x = _base.getAnch_x();
    m_iAnch_y = _base.getAnch_y();
    m_pParent = _base.getParent();
    /* 当前对象设置为父对象的子 */
    if (m_pParent) {
        m_pParent->addChild(this);
    }
    m_pChilds = new vector<Base *>;
}
