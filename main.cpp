#include <iostream>

#include "person.h"
#include "terminal.h"

using namespace std;

int main(void) {
    Person person;
    
    person.init();
    
    //关闭游戏控制模式
    startControlMode();
    
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
                }
            }
        }
    } while(1);

    //关闭游戏控制模式
    stopControlMode();
    
    return 0;
}
