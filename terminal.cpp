#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

#include "terminal.h"

using namespace std;

void Terminal::gotoPoint(int x, int y) {
    cout << "\e[" << (y >= 0 ? y : 0) << ";" << (x >= 0 ? x : 0) << "H";
}

void Terminal::cleanScreen() {
    cout << "\e[2J";
}

void Terminal::startControlMode() {    
    struct termios termInfo;
    /* 获取当前终端信息 */
    tcgetattr(STDIN_FILENO, &termInfo);

    /**
     * ICANON 如果在输入中看到"\n"或者EOF，会返回缓冲区内容
     * ECHO 用还控制回显
     */
    termInfo.c_lflag &= ~(ICANON | ECHO); // 设置新的终端属性
    /**
     * TCSANOW 告诉函数立即改变终端的STDIN_FILENO属性值
     */
    tcsetattr(STDIN_FILENO, TCSANOW, &termInfo);

    /* 隐藏光标 */
    hideCursor();

    /* 捕获Ctrl-C按键 */
    if (signal(SIGINT, Terminal::sign_quit) == SIG_ERR) {
        cout << "startControlMode" << endl;
        exit(-1);
    }
    /* 捕获Ctrl-\按键 */
    if (signal(SIGQUIT, Terminal::sign_quit) == SIG_ERR) {
        cout << "startControlMode" << endl;
        exit(-1);
    }
}

//捕捉退出程序信号
void Terminal::sign_quit(int sig) {
    stopControlMode();
    exit(1);
}

void Terminal::stopControlMode() {
    struct termios termInfo;

    /* 获取当前终端信息 */
    tcgetattr(STDIN_FILENO, &termInfo);

    /**
     * ICANON 如果在输入中看到"\n"或者EOF，会返回缓冲区内容
     * ECHO 用还控制回显
     */
    termInfo.c_lflag |= (ICANON | ECHO); // 设置新的终端属性
    /**
     * TCSANOW 告诉函数立即改变终端的STDIN_FILENO属性值
     */
    tcsetattr(STDIN_FILENO, TCSANOW, &termInfo);
    
    /* 显示光标 */
    displayCursor();

    /* 清屏 */
    cleanScreen();
    gotoPoint(0, 0);
}

//显示光标
void Terminal::displayCursor() {
    cout << "\e[?25h";
}

//隐藏光标
void Terminal::hideCursor() {
    cout << "\e[?25l";
}

//获取终端尺寸
void Terminal::getWs(int &x, int &y, int fd) {
    struct winsize size;  
    if (ioctl(fd, TIOCGWINSZ, (char*)&size) < 0) {
        cout << "ioctl" << endl;
        return;
    }
    y = size.ws_row;
    x = size.ws_col;
}

//设置终端尺寸
void Terminal::setWs(int x, int y, int fd) {
    struct winsize size;
    if (ioctl(fd, TIOCGWINSZ, (char*)&size) < 0) {
        cout << "ioctl" << endl;
        return;
    }
    size.ws_row = y;
    size.ws_col = x;
    if (ioctl(fd, TIOCSWINSZ, (char*)&size) < 0) {
        cout << "ioctl" << endl;
        return;
    }
} 

//等待特定按键
int Terminal::getKey(const int type) {
    char buf[4];
    size_t len;
    
    switch(type) {
    case 1:
        //获取方向按键
        while((len = read(STDIN_FILENO, buf, 3)) != -1) {
            if (3 == len && 27 == buf[0] && 91 == buf[1]) {
                return buf[2];
            }
            switch(buf[0]) {
            case 'w':
            case 'W':
                //上
                return UP;
            case 's':
            case 'S':
                //上
                return DOWN;
            case 'a':
            case 'A':
                //上
                return LEFT;
            case 'd':
            case 'D':
                //上
                return RIGHT;
            case ESC:
                //上
                return ESC;
            }
        }
        break;
    case 2:
        //确认键(ESC:退出;Enter：继续)
        while((len = read(STDIN_FILENO, buf, 3)) != -1) {
            if (1 == len && (GOON == buf[0] || ESC == buf[0])) {
                return buf[0];
            }
        }
        break;
    }
    return 0;
}
