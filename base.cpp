#include <vector>

#include "base.h"
#include "terminal.h"

using namespace std;

Base::Base(string _body, int _frontcolor, int _backcolor, int _width, int _height) {
    m_strBody = _body;
    m_iFrontColor = _frontcolor;
    m_iBackColor = _backcolor;
    m_iWidth = _width;
    m_iHeight = _height;
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

void Base::setFrontColor(int _frontcolor) {
    m_iFrontColor = _frontcolor;
}

void Base::setBackColor(int _backcolor) {
    m_iFrontColor = _backcolor;
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

void Base::setRelatAnch_x(int _anch_x) {
    m_iRelatAnch_x = _anch_x;
}

void Base::setRelatAnch_y(int _anch_y) {
    m_iRelatAnch_y = _anch_y;
}

void Base::setParent(Base &parent) {
    m_pParent = &parent;
}

void Base::addChild(Base &child) {
    m_pChilds->push_back(&child);
}

void Base::deleteChild(Base &child) {
    for (vector<Base *>::iterator iter = m_pChilds->begin(); iter != m_pChilds->end(); iter++) {
        if (*iter == &child) {
            m_pChilds->erase(iter);
        }
    }
}

void Base::print() const {
    string line;

    cleanScreen();
    for (int i = 0; i < m_iWidth; i++) {
        line += m_strBody;
    }
    for (int i = 0; i < m_iHeight; i++) {
        gotoPoint(m_iAnchor_x, m_iAnchor_y + i);
        colorPrint(line, m_iFrontColor, m_iBackColor);
    }
}
