#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "person.h"

using namespace std;

int main(void) {
    Person person;
    
    person.print();

    static struct termios oldt, newt;

    /* 将当前设置写入oldt。
     */
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    /* ICANON 如果在输入中看到"\n"或者EOF，会返回缓冲区内容
     * ECHO 用还控制回显
     */
    newt.c_lflag &=~(ICANON | ECHO); // 设置新的终端属性
    /*
     *TCSANOW 告诉函数立即改变终端的STDIN_FILENO属性值
     */
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );

    int ret = -1;
    do {
      int key1 = getchar();
      if (27 == key1) {
      	int key2 = getchar();
	if (91 == key2) {
	  int key3 = getchar();
	  switch(key3) {
	  case 65:
	    ret = person.moveUp();
	    break;
	  case 66:
	    ret = person.moveDown();
	    break;
	  case 68:
	    ret = person.moveLeft();
	    break;
	  case 67:
	    ret = person.moveRight();
	    break;
	  }
	  if (MOVE_OUT == ret) {
	    cout << "Congrulation, you succeed!!!" << endl;
	    break;
	  }
	}
      }
    } while(1);

    // 恢复终端设置
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    
    return 0;
}
