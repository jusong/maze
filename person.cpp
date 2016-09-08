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

/* 每走一步都会检查：会不会撞墙，会不会退出去了，或者成功走出去了 */
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

/* 移动人类 */
void Person::move(int _x, int _y) {
    this->m_iPreX = this->m_iX;
    this->m_iPreY = this->m_iY;
    this->m_iX = _x;
    this->m_iY = _y;
    this->print();
}

/* 初始化 */
void Person::init() {
    //画迷宫地图
    this->m_mazeMap->print();
    //画人
    this->print();
}

/* 画人 */
void Person::print() {
    //首先把上个位置的人类擦除掉
    cout << "\e[" << this->m_mazeMap->getAnchor_y() + this-> m_iPreY << ";" << this->m_mazeMap->getAnchor_x() + this->m_iPreX << "H";
    cout << "\e[36;46m" << this->m_mazeMap->getRoad() << "\e[0m";

    //然后再在新的位置上打印出人类
    cout << "\e[" << this->m_mazeMap->getAnchor_y() + this-> m_iY << ";" << this->m_mazeMap->getAnchor_x() + this->m_iX << "H";
    cout << "\e[30;42m" << this->m_strBody << "\e[0m";
    cout << "\e[20;0H";

    //最后刷新输出缓冲区
    cout.flush();
}

