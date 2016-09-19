#ifndef CANVAS_H
#define CANVAS_H

#include "base.h"
#include "maze.h"
#include "person.h"
#include "text_button.h"

class Canvas : public Base {
 public:
    Canvas();
    void printSelf() const;
    
    Maze& getMaze();
    int getScore() const;
    int getCountDown() const;
    int getStepCount() const;
    int getLevel() const;
    
    void setScore(const int _score);
    void setCountDown(const int _count_down);
    void setStepCount(const int _step_count);
    void setLevel(const int _level);
    void addScore(const int _score);
    void addCountDown(const int _count_down);
    void addStepCount(const int _step_count);
    void addLevel(const int _level);

    void addPerson(Person &_person);
    
 private:
    Base m_baseMazeMap;		//迷宫地图
    Base m_baseInfoBoard;	//信息展示板
    string m_strTitle;		//名称

    Maze m_Maze;					//迷宫
    TextButton m_txtBtnScore;		//分数
    TextButton m_txtBtnCountDown;	//倒计时
    TextButton m_txtBtnStepCount;	//步数
    TextButton m_txtBtnLevel;		//关卡
};

#endif
