#ifndef MAZE_H
#define MAZE_H

#include <vector>

using namespace std;

#define WALL		2 //墙
#define ROAD		1 //道

#define MAP_NO		0 //撞墙
#define MAP_YES		1 //正常
#define MAP_OUT		2 //走出迷宫

/********************************
 * 迷宫对象
 ********************************/
class Maze {
 public:
    Maze(int _maze = 0, string _wall = "*", string _road = " ", int _anchor_x = 10, int _anchor_y = 10);
    void setWall(const string);
    void setRoad(const string);
    string getRoad();
    void setAnchor_x(const int);
    void setAnchor_y(const int);
    int getAnchor_x();
    int getAnchor_y();
    
    void print() const;
    int checkPoint(int _x, int _y) const;

 private:
    const int m_intMaze;
    string m_strWall;
    string m_strRoad;
    int m_iAnchor_x;
    int m_iAnchor_y;
};

#endif
