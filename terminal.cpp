#include <iostream>

#include "terminal.h"

using namespace std;

void gotoPoint(int x, int y) {
    cout << "\e[" << y + 1 << ";" << x+1 << "H";
}

void cleanScreen() {
    cout << "\e[2J";
}

void startControlMode() {
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
}

void stopControlMode() {
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
}

//显示光标
void displayCursor() {
    cout << "\e[?25h";
}

//隐藏光标
void hideCursor() {
    cout << "\e[?25l";
}
