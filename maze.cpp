#include <iostream>
#include <vector>

#include "maze.h"

using namespace std;

Maze::Maze(const vector[] _maze, string _wall, string _road, int _anchor_x, int _anchor_y) {
  m_strWall = _wall;
  m_strRoad = _road;
  m_iAnchor_x = _anchor_x;
  m_iAnchor_y = _anchor_y;
}

void Maze::setWall(string _wall) {
  m_strWall = _wall;
}

void Maze::setRoad(string _road) {
  m_strRoad = _road;
}

void Maze::setAnchor_x(int _anchor_x) {
  m_iAnchor_x = _anchor_x;
}

void Maze::setAnchor_y(int _anchor_y) {
  m_iAnchor_y = _anchor_y;
}

void Maze::print() {
}
