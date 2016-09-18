#include <iostream>
#include <vector>

#include "canvas.h"
#include "terminal.h"

using namespace std;

Canvas::Canvas():Base(49, 20) {
    setColor(44);
    setTag("master_canvas");
    //迷宫地图背景
    m_baseMazeMap.setParent(this);
    m_baseMazeMap.setWidth(32);
    m_baseMazeMap.setHeight(-2);
    m_baseMazeMap.setColor(47);
    m_baseMazeMap.setAnch_x(1);
    m_baseMazeMap.setAnch_y(1);
    m_baseMazeMap.setTag("maze_bg");
    //迷宫地图
    m_Maze.setParent(&m_baseMazeMap);
    m_Maze.setTag("maze_map");
    m_Maze.setAnch_x((m_baseMazeMap.getWidth() - m_Maze.getWidth())/ 2);
    m_Maze.setAnch_y((m_baseMazeMap.getHeight() - m_Maze.getHeight())/ 2);
    //信息展示板
    m_baseInfoBoard.setParent(this);
    m_baseInfoBoard.setWidth(14);
    m_baseInfoBoard.setHeight(-2);
    m_baseInfoBoard.setColor(45);
    m_baseInfoBoard.setAnch_x(-15);
    m_baseInfoBoard.setAnch_y(1);
    m_baseInfoBoard.setTag("info_board");
    //分数
    m_txtBtnScore.setParent(&m_baseInfoBoard);
    m_txtBtnScore.setTitle("分数");
    m_txtBtnScore.setContent(0);
    m_txtBtnScore.setAnch_x(1);
    m_txtBtnScore.setAnch_y(1);
    m_txtBtnScore.setTag("score");
    //倒计时
    m_txtBtnCountDown.setParent(&m_baseInfoBoard);
    m_txtBtnCountDown.setTitle("倒计时");
    m_txtBtnCountDown.setContent(100);
    m_txtBtnCountDown.setAnch_x(1);
    m_txtBtnCountDown.setAnch_y(3);
    m_txtBtnCountDown.setTag("count_down");
    //步数
    m_txtBtnStepCount.setParent(&m_baseInfoBoard);
    m_txtBtnStepCount.setTitle("步数");
    m_txtBtnStepCount.setContent(0);
    m_txtBtnStepCount.setAnch_x(1);
    m_txtBtnStepCount.setAnch_y(5);
    m_txtBtnStepCount.setTag("step_count");
    //关卡
    m_txtBtnLevel.setParent(&m_baseInfoBoard);
    m_txtBtnLevel.setTitle("关卡");
    m_txtBtnLevel.setContent(1);
    m_txtBtnLevel.setAnch_x(1);
    m_txtBtnLevel.setAnch_y(7);
    m_txtBtnLevel.setTag("level");
}

Maze& Canvas::getMaze() {
    return m_Maze;
}

int Canvas::getScore() const {
    return m_txtBtnScore.getContent();
}

int Canvas::getCountDown() const {
    return m_txtBtnCountDown.getContent();
}

int Canvas::getStepCount() const {
    return m_txtBtnStepCount.getContent();
}

int Canvas::getLevel() const {
    return m_txtBtnLevel.getContent();
}

void Canvas::setScore(const int _score) {
    m_txtBtnScore.setContent(_score);
    m_txtBtnScore.print();
}

void Canvas::setCountDown(const int _count_down) {
    m_txtBtnCountDown.setContent(_count_down);
    m_txtBtnCountDown.print();
}

void Canvas::setStepCount(const int _step_count) {
    m_txtBtnStepCount.setContent(_step_count);
    m_txtBtnStepCount.print();
}

void Canvas::setLevel(const int _level) {
    m_txtBtnLevel.setContent(_level);
    m_txtBtnLevel.print();
}

void Canvas::printSelf() const {
    int width = getWidth();
    int height = getHeight();
    
    /* 画背景 */
    string line;
    for (int i = 0; i < width; i++) {
        line += m_strBody;
    }
    int anchX = getAnch_x();
    int anchY = getAnch_y();
    for (int i = 0; i < height; i++) {
        Terminal::gotoPoint(anchX, anchY + i);
        Terminal::colorPrint(line, m_iColor);
    }
    /* 标题 */
    Terminal::gotoPoint(anchX + width / 2 - m_strTitle.size() / 2, anchY);
    Terminal::colorPrint(m_strTitle, 40);
}

void Canvas::addPerson(Person &_person) {
    _person.setParent(&m_Maze);
}
