#ifndef MAZE_H
#define MAZE_H

#include <vector>
using namespace std;

/********************************
 * 迷宫对象
 ********************************/
class Maze {
 public:
  Maze(const vector[] _maze, string _wall = "*", string _road = " ", int _anchor_x = 10, int _anchor_y = 10);
  void setWall(const string);
  void setRoad(const string);
  void setAnchor_x(const int);
  void setAnchor_y(const int);
  void setMaze(const vector[]);
  void print() const;
  
 private:
  vector[] m_vecMaze;
  string m_strWall;
  string m_strRoad;
  int m_iAnchor_x;
  int m_iAnchor_y;
};

#endif
