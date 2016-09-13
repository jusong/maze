#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <time.h>

#include "base.h"
#include "terminal.h"

using namespace std;

Base::Base(int _width, int _height) {
    m_iWidth = _width;
    m_iHeight = _height;
    m_strBody = " ";
    m_iColor = 0;
    m_iAnch_x = m_iAnch_y = 0;
    m_pParent = NULL;
    m_pChilds = new vector<Base *>;
}

Base::~Base() {
    delete m_pChilds;
    m_pChilds = NULL;
}

void Base::setBody(string _body) {
    m_strBody = _body;
}

void Base::setColor(int _color) {
    m_iColor = _color;
}

void Base::setWidth(int _width) {
    m_iWidth = _width;
}

void Base::setHeight(int _height) {
    m_iHeight = _height;
}

void Base::setAnch_x(int _anch_x) {
    m_iAnch_x = _anch_x;
}

void Base::setAnch_y(int _anch_y) {
    m_iAnch_y = _anch_y;
}

int Base::getWidth() const {
    return m_iWidth;
}

int Base::getHeight() const {
    return m_iHeight;
}

int Base::getAnch_x() const {
    if (m_pParent) {
        return m_pParent->getAnch_x() + ((m_iAnch_x >= 0) ? m_iAnch_x : (m_pParent->getWidth() + m_iAnch_x));
    } else {
        return abs(m_iAnch_x);
    }
}

int Base::getAnch_y() const {
    if (m_pParent) {
       	return m_pParent->getAnch_y() + ((m_iAnch_y >= 0) ? m_iAnch_y : (m_pParent->getHeight() + m_iAnch_y));
    } else {
        return abs(m_iAnch_y);
    }
}

vector<Base *>* Base::getChilds() const {
    return m_pChilds;
}

void Base::setParent(Base *parent) {
    if (m_pParent != parent) {
        m_pParent = parent;
        parent->addChild(this);
    }
}

void Base::addChild(Base *child) {
    vector<Base *>::iterator iter;
    iter = find(m_pChilds->begin(), m_pChilds->end(), child);
    if (iter == m_pChilds->end()) {
        m_pChilds->push_back(child);
        child->setParent(this);
    }
}

void Base::deleteChild(Base *child) {
    vector<Base *>::iterator iter;
    iter = find(m_pChilds->begin(), m_pChilds->end(), child);
    if (iter != m_pChilds->end()) {
        m_pChilds->erase(iter);
    }
}

void Base::printSelf() const {
    /* 画背景 */
    string line;
    for (int i = 0; i < m_iWidth; i++) {
        line += m_strBody;
    }
    int anchX = getAnch_x();
    int anchY = getAnch_y();
    for (int i = 0; i < m_iHeight; i++) {
        gotoPoint(anchX, anchY + i);
        colorPrint(line, m_iColor);
    }
}

void Base::print() const {
    /* 一级画布，清屏刷新 */
    if (!m_pParent) {
        /* 清屏 */
        cleanScreen();
    }

    /* 画当前画布 */
    printSelf();
    
    /* 同级右支画布刷新 */
    if (m_pParent) {
        int flag = 0;
        vector<Base *> *childs = m_pParent->getChilds();
        for (auto i : *childs) {
            if (flag) {
                i->printSelf();
            }
            if (i == this) {
                flag = 1;
            }
        }
    }

    /* 刷新子级画布 */
    for (auto i : *m_pChilds) {
        i->printSelf();
    }
    
    /* 刷新输出缓存 */
    cout.flush();
}
