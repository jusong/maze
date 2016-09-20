#include <iostream>
#include <sstream>
#include <math.h>
#include <time.h>

#include "text_button.h"
#include "terminal.h"
#include "config.h"

using namespace std;

TextButton::TextButton(const string &_title, int _content): Base(TXTBTN_WIDTH, TXTBTN_HEIGHT){
    m_strTitle = _title;
    m_iContent = _content;
    m_iTitleColor = m_iContentColor = 0;
}

TextButton::TextButton(const TextButton &textbtn):Base(textbtn) {
    m_strTitle = textbtn.getTitle();
    m_iContent = textbtn.getContent();
    m_iTitleColor = textbtn.getTitleColor();
    m_iContentColor = textbtn.getContentColor();
}

void TextButton::setTitle(const string &_title) {
    m_strTitle = _title;
}

void TextButton::setContent(const int _content) {
    m_iContent = _content;
}

void TextButton::addContent(const int _content) {
    m_iContent += _content;
}

void TextButton::setTitleColor(const int _title_color) {
    m_iTitleColor = _title_color;
}

void TextButton::setContentColor(const int _content_color) {
    m_iContentColor = _content_color;
}

string TextButton::getTitle() const {
    return m_strTitle;
}

int TextButton::getContent() const {
    return m_iContent;
}

int TextButton::getTitleColor() const {
    return m_iTitleColor;
}

int TextButton::getContentColor() const {
    return m_iContentColor;
}

void TextButton::printSelf() const {
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

    /* 输出内容 */
    stringstream ss;
    ss.str("");
    ss << m_iContent;
    string content;
    ss >> content;
    //中文3个字节，显示出来占用俩个字符位置
    int contentLen = m_strTitle.size() * 2 / 3 + 1 + content.size();
    int textAnchX = anchX + (int)floor((width - contentLen) / 2.0);
    int textAnchY = anchY + (int)floor(height / 2.0);
    Terminal::gotoPoint(textAnchX, textAnchY);
    Terminal::colorPrint(m_strTitle + ":", m_iColor, m_iTitleColor);
    Terminal::colorPrint(content, m_iColor, m_iContentColor);
}
