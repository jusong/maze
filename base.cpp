#include <stdlib.h>
#include <stdio.h>
#include <vector>

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

void Base::setParent(Base *parent) {
    m_pParent = parent;
}

void Base::addChild(Base *child) {
    m_pChilds->push_back(child);
    child->setParent(this);
}

void Base::deleteChild(Base *child) {
    for (vector<Base *>::iterator iter = m_pChilds->begin(); iter != m_pChilds->end(); iter++) {
        if (*iter == child) {
            m_pChilds->erase(iter);
        }
    }
}

void Base::print() const {
    string line;

    /* 清屏 */
    cleanScreen();

    /* 刷新父级画布 */
    if (m_pParent) {
        m_pParent->print();
    }
    
    /* 画背景 */
    for (int i = 0; i < m_iWidth; i++) {
        line += m_strBody;
    }
    int anchX = getAnch_x();
    int anchY = getAnch_y();
    for (int i = 0; i < m_iHeight; i++) {
        gotoPoint(anchX, anchY + i);
        colorPrint(line, m_iColor);
    }

    /* 刷新输出缓存 */
    cout.flush();
}
