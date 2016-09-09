#include <iostream>

#include "canvas.h"

int main(void) 
{

    Canvas cv;

    cv.setAnchor_x(20);
    cv.setAnchor_y(2);
    cv.setFrontColor(32);
    cv.print();
    
    return 0;
}
