#include <iostream>
#include <signal.h>

#include "terminal.h"

using namespace std;

void Terminal::gotoPoint(int x, int y) {
    cout << "\e[" << (y >= 0 ? y + 1 : 0) << ";" << (x >= 0 ? x + 1: 0) << "H";
}

void Terminal::cleanScreen() {
    cout << "\e[2J";
}

void Terminal::startControlMode() {
    int x, y;
    getWs(x, y);
    if (x < 63 || y < 27) {
        cout << "Exit here, window size not satisfy(63x27)!" << endl;
        exit(1);
    }
    
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
        perror("startControlMode");
        exit(-1);
    }
    /* 捕获Ctrl-\按键 */
    if (signal(SIGQUIT, Terminal::sign_quit) == SIG_ERR) {
        perror("startControlMode");
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
        perror("ioctl");
        return;
    }
    y = size.ws_row;
    x = size.ws_col;
}

//设置终端尺寸
void Terminal::setWs(int x, int y, int fd) {
    struct winsize size;
    if (ioctl(fd, TIOCGWINSZ, (char*)&size) < 0) {
        perror("ioctl");
        return;
    }
    size.ws_row = y;
    size.ws_col = x;
    if (ioctl(fd, TIOCSWINSZ, (char*)&size) < 0) {
        perror("ioctl");
        return;
    }
} 
