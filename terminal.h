#ifndef TERMINAL_H
#define TERMINAL_H

#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>  
#include <signal.h>  
  
#include <iostream>

using namespace std;

#define UP		65	//上
#define DOWN	66	//下
#define LEFT	68	//左
#define RIGHT	67	//右
#define GOON	10	//继续
#define ESC		27	//退出

namespace Terminal {
    //定位光标到（x,y）
    //@param int x 横坐标
    //@param int y 纵坐标
    void gotoPoint(int x, int y);

    //按照指定颜色打印
    //@param T content 打印的内容
    //@param int backcolor 背景色
    //@param int frontcolor 前景色
    template<typename T>
    void colorPrint(const T &content, int backcolor = 0, int frontcolor = 0) {
        cout << "\e[" << (frontcolor >= 0 ? frontcolor : 0) << ";" << (backcolor >= 0 ? backcolor : 0) << "m" << content << "\e[0m";
    }

    //清屏，光标定位到(0,0)
    void cleanScreen();

    //捕捉退出程序信号
    void sign_quit(int sig);

    //开启终端控制模式: 及时相应键盘输入（终端非规范模式），关闭回显
    void startControlMode();

    //关闭终端控制模式: 终端规范模式，打开回显
    void stopControlMode();

    //显示光标
    void displayCursor();

    //隐藏光标
    void hideCursor();

    //获取终端尺寸
    void getWs(int &x, int &y, int fd = STDIN_FILENO);
    
    //设置终端尺寸
    void setWs(int x, int y, int fd = STDIN_FILENO);

    //等待特定按键
    int getKey(const int type);
};
    
#endif
