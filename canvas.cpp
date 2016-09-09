#include <iostream>
#include <vector>

#include "canvas.h"
#include "terminal.h"

using namespace std;

Canvas::Canvas(string _body, int _frontcolor, int _backcolor, int _width, int _height):Base(_body, _frontcolor, _backcolor, _width, _height) {
    m_iAnchor_x = 0;
    m_iAnchor_y = 0;
}

void Canvas::setAnchor_x(int _anchor_x) {
    m_iAnchor_x = _anchor_x;
}

void Canvas::setAnchor_y(int _anchor_y) {
    m_iAnchor_y = _anchor_y;
}

void Canvas::print() const {
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
