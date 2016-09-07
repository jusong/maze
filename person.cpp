#include <iostream>
#include "person.h"

using namespace std;

Person::Person(int _x, int _y, string _body, int _maze, string _wall, string _road, int _anchor_x, int _anchor_y) {
    this->m_iX = this->m_iPreX = _x;
    this->m_iY = this->m_iPreY = _y;
    this->m_strBody = _body;
    this->m_mazeMap = new Maze(_maze, _wall, _road, _anchor_x, _anchor_y);
}

Person::~Person() {
    delete this->m_mazeMap;
    this->m_mazeMap = NULL;
}

/* 上移 */
int Person::moveUp() {
    int ret = this->checkMove(this->m_iX, this->m_iY - 1);
    if (MOVE_YES == ret) {
        this->move(this->m_iX, this->m_iY - 1);
    }
    return ret;
}

/* 下移 */
int Person::moveDown() {
    int ret = this->checkMove(this->m_iX, this->m_iY + 1);
    if (MOVE_YES == ret) {
        this->move(this->m_iX, this->m_iY + 1);
    }
    return ret;
}

/* 左移 */
int Person::moveLeft() {
    int ret = this->checkMove(this->m_iX - 1, this->m_iY);
    if (MOVE_YES == ret) {
        this->move(this->m_iX - 1, this->m_iY);
    }
    return ret;
}

/* 右移 */
int Person::moveRight() {
    int ret = this->checkMove(this->m_iX + 1, this->m_iY);
    if (MOVE_YES == ret) {
        this->move(this->m_iX + 1, this->m_iY);
    }
    return ret;
}

int Person::checkMove(int _x, int _y) {
    int ret = this->m_mazeMap->checkPoint(_x, _y);
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

void Person::move(int _x, int _y) {
    this->m_iPreX = this->m_iX;
    this->m_iPreY = this->m_iY;
    this->m_iX = _x;
    this->m_iY = _y;
    this->print();
}

void Person::print() {
    this->m_mazeMap->print();
    cout << "\e[" << this->m_mazeMap->getAnchor_y() + this-> m_iPreY << ";" << this->m_mazeMap->getAnchor_x() + this->m_iPreX << "H";
    cout << this->m_mazeMap->getRoad();
    cout << "\e[" << this->m_mazeMap->getAnchor_y() + this-> m_iY << ";" << this->m_mazeMap->getAnchor_x() + this->m_iX << "H";
    cout << this->m_strBody;
    cout << "\e[20;0H";
    cout.flush();
}

