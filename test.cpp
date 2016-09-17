#include <iostream>
#include <unistd.h>
#include <sstream>
#include <time.h>
#include <math.h>

#include "terminal.h"
#include "base.h"
#include "text_button.h"

using namespace std;

void sign_winch(int sig);

Base base;

int main(void) {
    Terminal::startControlMode();
    
    /* 捕获窗口变化 */
    if (signal(SIGWINCH, sign_winch) == SIG_ERR) {
        perror("signal:sign_winch");
        exit(-1);
    }

    base.setColor(44);
    // base.print();
    // sleep(1);
    
    Base base1;
    base1.setParent(&base);
    base1.setWidth(-23);
    base1.setHeight(-2);
    base1.setAnch_x(1);
    base1.setAnch_y(1);
    base1.setColor(46);
    // base1.print();
    // sleep(1);
    
    Base base2;
    base2.setParent(&base);
    base2.setWidth(20);
    base2.setHeight(-2);
    base2.setAnch_x(-21);
    base2.setAnch_y(1);
    base2.setColor(43);
    // base2.print();
    // sleep(1);
    
    TextButton textbtn;
    textbtn.setParent(&base2);
    textbtn.setTitle("分数");
    textbtn.setContent("2");
    textbtn.setColor(45);
    textbtn.setWidth(18);
    textbtn.setHeight(3);
    textbtn.setAnch_x(1);
    textbtn.setAnch_y(1);
    //textbtn.print();

    TextButton textbtn1;
    textbtn1.setParent(&base2);
    textbtn1.setTitle("步数");
    textbtn1.setContent("100");
    textbtn1.setColor(41);
    textbtn1.setWidth(18);
    textbtn1.setHeight(3);
    // textbtn1.setAnch_x(5);
    // textbtn1.setAnch_y(3);
    textbtn1.setAnch_x(1);
    textbtn1.setAnch_y(6);
    //textbtn1.print();

    TextButton textbtn2;
    textbtn2.setParent(&base2);
    textbtn2.setTitle("时间");
    textbtn2.setContent("00:00:00");
    textbtn2.setColor(47);
    textbtn2.setWidth(18);
    textbtn2.setHeight(3);
    // textbtn2.setAnch_y(3);
    textbtn2.setAnch_x(1);
    textbtn2.setAnch_y(11);
    //textbtn2.print();

    base.print();
    sleep(3);
    
    stringstream ss;
    for (int i = 0; i < 1000; i += 1) {
        ss.str("");
        ss << i;
        textbtn1.setContent(ss.str());
        
        ss.str("");
        ss << (i * i);
        textbtn.setContent(ss.str());

        ss.str("");
        ss << time(NULL);
        textbtn2.setContent(ss.str());
        
        textbtn.print();
        sleep(1);
    }

    Terminal::stopControlMode();
    
    return 0;
}

void sign_winch(int sig) {
    int x, y;
    Terminal::getWs(x, y);
    x = floor(x * 0.8);
    y = floor(x * 5.0 / 16.0);
    if ( y < 20) {
        Terminal::stopControlMode();
        cout << "Exit here, window size not satisfy(100x20)!" << endl;
        exit(1);
    }
    base.setWidth(x);
    base.setHeight(y);
    Terminal::cleanScreen();
    base.print();
}
