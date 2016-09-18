#include <iostream>

#include "maze.h"
#include "person.h"
#include "terminal.h"

using namespace std;

Person::Person(string _body) {
    m_iX = m_iPreX = 0;
    m_iY = m_iPreY = 1;
    m_strBody = _body;
}

/* 上移 */
int Person::moveUp() {
    int ret = checkMove(m_iX, m_iY - 1);
    if (MOVE_YES == ret) {
        move(m_iX, m_iY - 1);
    }
    return ret;
}

/* 下移 */
int Person::moveDown() {
    int ret = checkMove(m_iX, m_iY + 1);
    if (MOVE_YES == ret) {
        move(m_iX, m_iY + 1);
    }
    return ret;
}

/* 左移 */
int Person::moveLeft() {
    int ret = checkMove(m_iX - 1, m_iY);
    if (MOVE_YES == ret) {
        move(m_iX - 1, m_iY);
    }
    return ret;
}

/* 右移 */
int Person::moveRight() {
    int ret = checkMove(m_iX + 1, m_iY);
    if (MOVE_YES == ret) {
        move(m_iX + 1, m_iY);
    }
    return ret;
}

/* 每走一步都会检查：会不会撞墙，会不会退出去了，或者成功走出去了 */
int Person::checkMove(int _x, int _y) const {
    Maze *parent = (Maze *)getParent();
    int ret = parent->checkPoint(_x, _y);
    if (MAP_YES == ret) {
        /* 正常 */
        return MOVE_YES;
    } else if (MAP_NO == ret) {
        /* 撞墙 */
        return MOVE_NO;
    } else if (MAP_OUT == ret) {
        if (-1 == _x && 1 == _y) {
            /* 从入口出去，不允许 */
            return MOVE_NO;
        } else {
            /* 走出迷宫 */
            return MOVE_OUT;
        }
    }
}

/* 移动人类 */
void Person::move(int _x, int _y) {
    m_iPreX = m_iX;
    m_iPreY = m_iY;
    m_iX = _x;
    m_iY = _y;
    print();
}

/* 画人 */
void Person::printSelf() const {
    //首先把上个位置的人类擦除掉
    Maze *parent = (Maze *)getParent();
    int anchX = parent->getAnch_x();
    int anchY = parent->getAnch_y();
    Terminal::gotoPoint(anchX + m_iPreX, anchY + m_iPreY);
    Terminal::colorPrint(" ", parent->getRoadColor());

    //然后再在新的位置上打印出人类
    Terminal::gotoPoint(anchX + m_iX, anchY + m_iY);
    Terminal::colorPrint(m_strBody, m_iColor, m_iBodyColor);
}

int Person::getPosX() const {
    return m_iX;
}

int Person::getPosY() const {
    return m_iY;
}

int Person::getBodyColor() const {
    return m_iBodyColor;
}

void Person::setPosX(const int _x) {
    m_iX = _x;
}

void Person::setPosY(const int _y) {
    m_iY = _y;
}

void Person::setBody(const string _body) {
    m_strBody = _body;
}

void Person::setBodyColor(const int _body_color) {
    m_iBodyColor = _body_color;
}
