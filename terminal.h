#ifndef COMMON_H
#define COMMON_H

#include <termios.h>
#include <unistd.h>

#include <iostream>

using namespace std;

//定位光标到（x,y）
//@param int x 横坐标
//@param int y 纵坐标
void gotoPoint(int x, int y);

//按照指定颜色打印
//@param T content 打印的内容
//@param int frontcolor 前景色
//@param int backcolor 背景色
template<typename T>
void colorPrint(const T &content, int frontcolor, int backcolor) {
    cout << "\e[" << frontcolor << ";" << backcolor << "m" << content << "\e[0m";
}

//清屏，光标定位到(0,0)
void cleanScreen();

//开启终端控制模式: 及时相应键盘输入（终端非规范模式），关闭回显
void startControlMode();

//关闭终端控制模式: 终端规范模式，打开回显
void stopControlMode();
    
#endif
