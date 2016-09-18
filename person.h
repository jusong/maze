#ifndef PERSON_H
#define PERSON_H

#include "base.h"

#define MOVE_NO		0 //撞墙
#define MOVE_YES	1 //正常
#define MOVE_OUT	2 //走出迷宫

/* 人类 */
class Person: public Base {

 public:
    Person(string _body = " ");
    int moveUp();
    int moveDown();
    int moveLeft();
    int moveRight();
    void printSelf() const;
    int checkMove(int _x, int _y) const;
    
    int getPosX() const;
    int getPosY() const;
    int getBodyColor() const;
    
    void setPosX(const int _x);
    void setPosY(const int _y);
    void setBody(const string _body);
    void setBodyColor(const int _body_color);

 private:
    void move(int _x, int _y);
    
 private:
    int m_iX; //位置横坐标
    int m_iY; //位置纵坐标
    int m_iPreX; //上一个位置横坐标
    int m_iPreY; //上一个位置纵坐标
    //int m_iDirection; //面朝方向
    string m_strBody; //身体形状,可以修改X为其他的东西
    int m_iBodyColor;
};

#endif
