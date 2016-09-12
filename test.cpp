#include <iostream>
#include <unistd.h>
#include <sstream>

#include "base.h"
#include "text_button.h"

using namespace std;

int main(void) 
{

    Base base;
    base.setAnch_x(20);
    base.setAnch_y(2);
    base.setColor(42);
    base.print();
    
    //    sleep(1);

    Base base1;
    base1.setParent(&base);
    base1.setWidth(12);
    base1.setAnch_x(-12);
    base1.setColor(43);
    base1.print();

    //    sleep(1);
    
    TextButton textbtn;
    textbtn.setParent(&base1);
    textbtn.setTitle("分数");
    textbtn.setContent("2");
    textbtn.setColor(45);
    textbtn.setWidth(10);
    textbtn.setHeight(3);
    textbtn.setAnch_x(1);
    textbtn.setAnch_y(1);
    textbtn.print();

    stringstream ss;
    for (int i = 0; i < 100; i++) {
        ss.str("");
        ss << i;
        textbtn.setContent(ss.str());
        textbtn.print();
        sleep(1);
    }

    return 0;
}
