#include <iostream>

#include "canvas.h"
#include "person.h"
#include "terminal.h"
#include "config.h"

using namespace std;

void sig_action(int sig);

Canvas canvas;

int main(void) {
    //关闭游戏控制模式
    Terminal::startControlMode();

    // 捕获定时器信号
    if (signal(SIGALRM, sig_action) == SIG_ERR) {
        perror("signal:SIGALRM");
        exit(-1);
    }
    // 捕获窗口变化
    if (signal(SIGWINCH, sig_action) == SIG_ERR) {
        perror("signal:SIGWINCH");
        exit(-1);
    }

    Person person("A");
    person.setColor(PERSON_BG_COLOR);
    person.setBodyColor(PERSON_FT_COLOR);
    canvas.addPerson(person);
    canvas.setTitle("迷宫游戏");
    canvas.init();
    
    int ret;
    do {
        switch(Terminal::getKey(1)) {
        case UP:
            ret = person.moveUp();
            break;
        case DOWN:
            ret = person.moveDown();
            break;
        case LEFT:
            ret = person.moveLeft();
            break;
        case RIGHT:
            ret = person.moveRight();
            break;
        case ESC:
            Terminal::stopControlMode();
            return 0;
		default :
			ret = -1;
			break;
        }
        if (MOVE_OUT == ret) {
            //成功走出迷宫
            canvas.success();
            if (ESC == Terminal::getKey(2)) {
                Terminal::stopControlMode();
                return 0;
            }
            if (!canvas.nextLevel()) {
                canvas.showInfo("You Vectory! \\^o^/\n\nPress Enter to restart!");
                if (ESC == Terminal::getKey(2)) {
                    Terminal::stopControlMode();
                    return 0;
                }
                canvas.init();
            }
        } else if (MOVE_YES == ret) {
            canvas.setStepCount(canvas.getStepCount() + 1);
        }
    } while(1);

    //关闭游戏控制模式
    Terminal::stopControlMode();
    
    return 0;
}

void sig_action(int sig) {
    switch (sig) {
    case SIGALRM:
        //定时器信号，更新倒计时
        if (canvas.getCountDown() > 0) {
            canvas.addCountDown(-1);
            alarm(1);
        } else {
            canvas.failed();
            if (ESC == Terminal::getKey(2)) {
                Terminal::stopControlMode();
                exit(0);
            }
            canvas.resetLevel();
        }
        break;
    case SIGWINCH:
        //窗口大小变化信号，重绘画面
        int winsX, winsY, canvasW, canvasH;
        Terminal::getWs(winsX, winsY);
        canvasW = canvas.getWidth();
        canvasH = canvas.getHeight();
        if (winsX < canvasW || winsY < canvasH) {
            cout << "Exit: Window size not satisfy(" << canvasW << "x" << canvasH << ")" << endl;
            exit(1);
        }
        canvas.setAnch_x((winsX - canvasW) / 2);
        canvas.setAnch_y((winsY - canvasH) / 2);
        canvas.print();
        alarm(1);
        break;
    }
}
