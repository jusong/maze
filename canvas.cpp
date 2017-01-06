#include <iostream>
#include <vector>
#include <sstream>

#include "canvas.h"
#include "terminal.h"
#include "common.h"
#include "config.h"

using namespace std;

Canvas::Canvas():Base(CANVAS_WIDTH, CANVAS_HEIGHT) {
    //底层画布
    setColor(CANVAS_BG_COLOR);
    setTag("master_canvas");
    int winsX, winsY;
    Terminal::getWs(winsX, winsY);
    if (winsX < CANVAS_WIDTH || winsY < CANVAS_HEIGHT) {
        cout << "Exit: Window size not satisfy(" << CANVAS_WIDTH << "x" << CANVAS_HEIGHT << ")" << endl;
        exit(1);
    }
    setAnch_x((winsX - CANVAS_WIDTH) / 2);
    setAnch_y((winsY - CANVAS_HEIGHT) / 2);
    
    //迷宫地图背景
    m_baseMazeMap.setParent(this);
    m_baseMazeMap.setWidth(MAZEMAP_BG_WIDTH);
    m_baseMazeMap.setHeight(MAZEMAP_BG_HEIGHT);
    m_baseMazeMap.setColor(MAZEMAP_BG_COLOR);
    m_baseMazeMap.setAnch_x(1);
    m_baseMazeMap.setAnch_y(1);
    m_baseMazeMap.setTag("maze_bg");
    
    //迷宫地图
    m_Maze.setParent(&m_baseMazeMap);
    m_Maze.setTag("maze_map");
    m_Maze.setAnch_x((m_baseMazeMap.getWidth() - m_Maze.getWidth()) / 2);
    m_Maze.setAnch_y((m_baseMazeMap.getHeight() - m_Maze.getHeight()) / 2);
    m_Maze.setWallColor(MAZEMAP_WALL_COLOR);
    m_Maze.setRoadColor(MAZEMAP_ROAD_COLOR);
	m_Maze.setMap(0);
    
    //信息展示板
    m_baseInfoBoard.setParent(this);
    m_baseInfoBoard.setWidth(INFOBROAD_BG_WIDTH);
    m_baseInfoBoard.setHeight(INFOBROAD_BG_HEIGHT);
    m_baseInfoBoard.setColor(INFOBROAD_BG_COLOR);
    m_baseInfoBoard.setAnch_x(-15);
    m_baseInfoBoard.setAnch_y(1);
    m_baseInfoBoard.setTag("info_board");
    
    //分数
    m_txtBtnScore.setParent(&m_baseInfoBoard);
    m_txtBtnScore.setTitle("总分");
    m_txtBtnScore.setContent(0);
    m_txtBtnScore.setAnch_x(1);
    m_txtBtnScore.setAnch_y(1);
    m_txtBtnScore.setTag("score");
    m_txtBtnScore.setColor(TXTBTN_BG_COLOR);
    m_txtBtnScore.setTitleColor(TXTBTN_TITLE_COLOR);
    m_txtBtnScore.setContentColor(TXTBTN_CONTENT_COLOR);
    
    //倒计时
    m_txtBtnCountDown.setParent(&m_baseInfoBoard);
    m_txtBtnCountDown.setTitle("倒计时");
    m_txtBtnCountDown.setContent(30);
    m_txtBtnCountDown.setAnch_x(1);
    m_txtBtnCountDown.setAnch_y(3);
    m_txtBtnCountDown.setTag("count_down");
    m_txtBtnCountDown.setColor(TXTBTN_BG_COLOR);
    m_txtBtnCountDown.setTitleColor(TXTBTN_TITLE_COLOR);
    m_txtBtnCountDown.setContentColor(TXTBTN_CONTENT_COLOR);
    
    //步数
    m_txtBtnStepCount.setParent(&m_baseInfoBoard);
    m_txtBtnStepCount.setTitle("步数");
    m_txtBtnStepCount.setContent(0);
    m_txtBtnStepCount.setAnch_x(1);
    m_txtBtnStepCount.setAnch_y(5);
    m_txtBtnStepCount.setTag("step_count");
    m_txtBtnStepCount.setColor(TXTBTN_BG_COLOR);
    m_txtBtnStepCount.setTitleColor(TXTBTN_TITLE_COLOR);
    m_txtBtnStepCount.setContentColor(TXTBTN_CONTENT_COLOR);
    
    //关卡
    m_txtBtnLevel.setParent(&m_baseInfoBoard);
    m_txtBtnLevel.setTitle("关卡");
    m_txtBtnLevel.setContent(1);
    m_txtBtnLevel.setAnch_x(1);
    m_txtBtnLevel.setAnch_y(7);
    m_txtBtnLevel.setTag("level");
    m_txtBtnLevel.setColor(TXTBTN_BG_COLOR);
    m_txtBtnLevel.setTitleColor(TXTBTN_TITLE_COLOR);
    m_txtBtnLevel.setContentColor(TXTBTN_CONTENT_COLOR);
}

void Canvas::init() {
    m_txtBtnCountDown.setContent(30); //倒计时=0
    m_txtBtnStepCount.setContent(0); //步数=0
    m_txtBtnLevel.setContent(1); //关卡=1
    m_txtBtnScore.setContent(0); //分数=0
	m_Maze.init();
    print();
    alarm(1);
}

bool Canvas::nextLevel() {
    if (m_Maze.nextMap()) {
        m_txtBtnCountDown.setContent(30); //倒计时=0
        m_txtBtnStepCount.setContent(0); //步数=0
        m_txtBtnLevel.addContent(1); //关卡+1
        print();
        alarm(1);
        return true;
    } else {
        return false;
    }
}

void Canvas::resetLevel() {
    m_Maze.reset();
    m_txtBtnCountDown.setContent(30); //倒计时=0
    m_txtBtnStepCount.setContent(0); //步数=0
    print();
    alarm(1);
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

void Canvas::addScore(const int _score) {
    m_txtBtnScore.addContent(_score);
    m_txtBtnScore.print();
}

void Canvas::addCountDown(const int _count_down) {
    m_txtBtnCountDown.addContent(_count_down);
    m_txtBtnCountDown.print();
}

void Canvas::addStepCount(const int _step_count) {
    m_txtBtnStepCount.addContent(_step_count);
    m_txtBtnStepCount.print();
}

void Canvas::addLevel(const int _level) {
    m_txtBtnLevel.addContent(_level);
    m_txtBtnLevel.print();
}

void Canvas::hiddenMaze() {
    m_Maze.setHidden(true);
    m_Maze.print();
}

//隐藏迷宫区域，显示通知信息
void Canvas::showInfo(const string _info) {
    hiddenMaze();
    int mapWidth = m_baseMazeMap.getWidth();
    int mapHeight = m_baseMazeMap.getHeight();
    int mapAnchX = m_baseMazeMap.getAnch_x();
    int mapAnchY = m_baseMazeMap.getAnch_y();
    vector<string> lineList = Common::split(_info, "\n");
    int anchX = mapAnchX + mapWidth / 2;
    int anchY = mapAnchY + (mapHeight - lineList.size()) / 2;
    int i = 0;
    for (string &line : lineList) {
        Terminal::gotoPoint(anchX - (line.size() / 2), anchY + i);
        Terminal::colorPrint(line, m_baseMazeMap.getColor());
        i++;
    }
    m_Maze.setHidden(false);
    cout.flush();
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
    Terminal::colorPrint(m_strTitle, m_iColor, 36);
}

void Canvas::addPerson(Person &_person) {
    _person.setParent(&m_Maze);
}

string& Canvas::getTitle() {
    return m_strTitle;
}

void Canvas::setTitle(const string _title) {
    m_strTitle = _title;
}

void Canvas::success() {
    alarm(0);
    int score = calScore();
    m_txtBtnScore.addContent(score); //分数+score
    stringstream ss;
    ss.str("");
    ss << "Succeed! ~^o^~\nYour score: " << score << "\n\nPress Enter to continue!";
    showInfo(ss.str());
}

void Canvas::failed() {
    alarm(0);
    showInfo("Wow! You failed! 〒_〒\n\nPress Enter to retry!");
}

int Canvas::calScore() {
    return int(70.0 / m_txtBtnStepCount.getContent() * m_txtBtnCountDown.getContent());
}
