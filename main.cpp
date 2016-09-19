#include <iostream>

#include "canvas.h"
#include "person.h"
#include "terminal.h"

using namespace std;

void sig_alarm(int sig);

Canvas canvas;

int main(void) {
    //关闭游戏控制模式
    Terminal::startControlMode();
    
    Person person;

    signal(SIGALRM, sig_alarm);
    
    canvas.setAnch_x(40);
    canvas.setAnch_y(5);
    canvas.addPerson(person);
    canvas.print();
    
    alarm(1);
    int ret = -1;
    do {
        int key1 = getchar();
        if (27 == key1) {
            int key2 = getchar();
            if (91 == key2) {
                int key3 = getchar();
                switch(key3) {
                case 65:
                    //上
                    ret = person.moveUp();
                    break;
                case 66:
                    //下
                    ret = person.moveDown();
                    break;
                case 68:
                    //左
                    ret = person.moveLeft();
                    break;
                case 67:
                    //右
                    ret = person.moveRight();
                    break;
                }
                if (MOVE_OUT == ret) {
                    //成功走出迷宫
                    cout << "Congrulation, you succeed!!!" << endl;
                    break;
                } else if (MOVE_YES == ret) {
                    canvas.setStepCount(canvas.getStepCount() + 1);
                }
            }
        }
    } while(1);

    //关闭游戏控制模式
    Terminal::stopControlMode();
    
    return 0;
}

void sig_alarm(int sig) {
    if (canvas.getCountDown() > 0) {
        canvas.addCountDown(-1);
        alarm(1);
    } else {
        cout << "Sorry, time ended, you failed!" << endl;
        //关闭游戏控制模式
        Terminal::stopControlMode();
        exit(1);
    }
}
