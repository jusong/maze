#include <iostream>
#include "maze.h"

using namespace std;

int main(void) {
  Maze maze(1, "#", " ", 40, 3);
  
  maze.print();

  return 0;
}
