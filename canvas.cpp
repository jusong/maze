#include <iostream>
#include "canvas.h"

using namespace std;

Canvas::Canvas(string _body, int _frontcolor, int _backcolor) {
    this->m_strBody = _body;
    this->m_iFrontColor = _frontcolor;
    this->m_iBackColor = _backcolor;
    this->m_iWidth = 1000;
    this->m_iHeight = 10;
    this->m_iAnchor_x = 0;
    this->m_iAnchor_y = 0;
    this->m_pParent = NULL;
    this->m_pChilds = new vector<void *>;
    this->m_iChildCount = 0;
}

Canvas::~Canvas() {
    delete this->m_pChilds;
    this->m_pChilds = NULL;
}

void Canvas::setBody(string _body) {
    this->m_strBody = _body;
}

void Canvas::setFrontColor(int _frontcolor) {
    this->m_iFrontColor = _frontcolor;
}

void Canvas::setBackColor(int _backcolor) {
    this->m_iFrontColor = _backcolor;
}

void Canvas::setWidth(int _width) {
    this->m_iWidth = _width;
}

void Canvas::setHeight(int _height) {
    this->m_iHeight = _height;
}

void Canvas::setAnchor_x(int _anchor_x) {
    this->m_iAnchor_x = _anchor_x;
}

void Canvas::setAnchor_y(int _anchor_y) {
    this->m_iAnchor_y = _anchor_y;
}

void Canvas::print() const {
    
}

    
