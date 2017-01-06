#ifndef MAZE_H
#define MAZE_H

#include <vector>

#include "base.h"

using namespace std;

#define WALL		2 //墙
#define ROAD		1 //道

#define MAP_NO		0 //撞墙
#define MAP_YES		1 //正常
#define MAP_OUT		2 //走出迷宫

/********************************
 * 迷宫对象
 ********************************/
class Maze: public Base {
 public:
    Maze();
    void setWallColor(const int _wall_color);
    void setRoadColor(const int _road_color);
    void setMap(const int _map);

    int getWallColor() const;
    int getRoadColor() const;
    int getMap() const;
    
    void printSelf() const;
    virtual int checkPoint(int _x, int _y) const;
    bool nextMap();
    void reset();
    void init();

 private:
    int m_iMap;
    int m_iWallColor;
    int m_iRoadColor;
    static vector< vector< vector<int> > > mazeMap;
};

#endif
