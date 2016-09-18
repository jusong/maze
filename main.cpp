#include <iostream>

#include "canvas.h"
#include "person.h"
#include "terminal.h"

using namespace std;

int main(void) {
    //关闭游戏控制模式
    Terminal::startControlMode();

    Canvas canvas;
    Person person;

    canvas.setAnch_x(40);
    canvas.setAnch_y(5);
    canvas.addPerson(person);
    canvas.print();
    
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
