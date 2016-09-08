#include <iostream>
#include <vector>

#include "maze.h"

using namespace std;


/* 地图的定义 */
vector< vector< vector<int> > > mazeMap = {
    {{WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
     {ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL},
     {WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, ROAD, WALL},
     {WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, WALL},
     {WALL, ROAD, WALL, WALL, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL},
     {WALL, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL},
     {WALL, ROAD, ROAD, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, ROAD, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, ROAD, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD},
     {WALL, ROAD, WALL, WALL, WALL, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, WALL, WALL, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, WALL, WALL},
     {WALL, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, WALL},
     {WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, ROAD, WALL},
     {WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, WALL},
     {WALL, ROAD, WALL, WALL, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, ROAD, WALL, WALL, ROAD, WALL, WALL, WALL, WALL},
     {WALL, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL},
     {WALL, ROAD, ROAD, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, ROAD, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, ROAD, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, WALL},
     {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}}
};

Maze::Maze(int _maze, string _wall, string _road, int _anchor_x, int _anchor_y):m_intMaze(_maze) {
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

string Maze::getRoad() {
    return m_strRoad;
}

void Maze::setAnchor_x(int _anchor_x) {
    m_iAnchor_x = _anchor_x;
}

void Maze::setAnchor_y(int _anchor_y) {
    m_iAnchor_y = _anchor_y;
}

/* 打印地图 */
void Maze::print() const {
    cout << "\e[2J";
    cout << "\e[" << this-> m_iAnchor_y - 2 << ";" << this->m_iAnchor_x + 1 << "H";
    cout << "<- 迷宫游戏 ->";
    int wall_len = this->m_strWall.size();

    for (int row = 0; row < mazeMap[this->m_intMaze].size(); row++) {
        for (int col = 0; col < mazeMap[this->m_intMaze][row].size(); col++) {
            cout << "\e[" << (row + this-> m_iAnchor_y) << ";" << (col * wall_len + this->m_iAnchor_x) << "H";
            if (mazeMap[this->m_intMaze][row][col] == WALL) {
                cout << this->m_strWall;
            } else if (mazeMap[this->m_intMaze][row][col] == ROAD) {
                cout << this->m_strRoad;
            }
        }
        cout << endl;
    }
    cout.flush();
}

/* 检查指定坐标在地图上的位置状态 */
int Maze::checkPoint(int _x, int _y) const {
    if (_y < 0 || _y >= mazeMap[this->m_intMaze].size()
        || _x < 0 || _x >= mazeMap[this->m_intMaze][_y].size()) {
        return MAP_OUT;
    } else if (WALL == mazeMap[this->m_intMaze][_y][_x]) {
        return MAP_NO;
    } else {
        return MAP_YES;
    }
}

int Maze::getAnchor_x() {
    return this->m_iAnchor_x;
}

int Maze::getAnchor_y() {
    return this->m_iAnchor_y;
}


