#include <iostream>
#include <unistd.h>
#include "person.h"

using namespace std;

int main(void) {
    Person person;

    person.print();
    sleep(1);
    
    person.moveRight();
    sleep(1);
    
    person.moveDown();
    sleep(1);
    person.moveDown();
    sleep(1);
    
    person.moveRight();
    sleep(1);    
    person.moveRight();
    sleep(1);
    
    person.moveUp();
    sleep(1); 
    person.moveUp();
    sleep(1);
    
    person.moveRight();
    sleep(1);    
    person.moveRight();
    sleep(1);
    
    person.moveDown();
    sleep(1);
    person.moveDown();
    sleep(1);
    
    person.moveRight();
    sleep(1);
    
    person.moveDown();
    sleep(1);
    person.moveDown();
    sleep(1);
    
    person.moveRight();
    sleep(1);    
    person.moveRight();
    sleep(1);
    person.moveRight();
    sleep(1);    
    person.moveRight();
    sleep(1);

    person.moveDown();
    sleep(1);
    person.moveDown();
    sleep(1);

    person.moveLeft();
    sleep(1);
    person.moveRight();
    sleep(1);
    person.moveRight();
    sleep(1);
    
    return 0;
}
