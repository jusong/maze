#include <iostream>
#include <math.h>

#include "text_button.h"
#include "terminal.h"

using namespace std;


TextButton::TextButton(const string &_title, const string &_content) {
    m_strTitle = _title;
    m_strContent = _content;
    m_iTitleColor = m_iContentColor = 0;
}

void TextButton::setTitle(const string &_title) {
    m_strTitle = _title;
}

void TextButton::setContent(const string &_content) {
    m_strContent = _content;
}

void TextButton::setTitleColor(int _title_color) {
    m_iTitleColor = _title_color;
}

void TextButton::setContentColor(int _content_color) {
    m_iContentColor = _content_color;
}

void TextButton::print() const {
    string line;

    /* 清屏 */
    cleanScreen();

    /* 刷新父级画布 */
    if (m_pParent) {
        m_pParent->print();
    }
    
    /* 画背景 */
    for (int i = 0; i < m_iWidth; i++) {
        line += m_strBody;
    }
    int anchX = getAnch_x();
    int anchY = getAnch_y();
    for (int i = 0; i < m_iHeight; i++) {
        gotoPoint(anchX, anchY + i);
        colorPrint(line, m_iColor);
    }

    /* 输出内容 */
    int contentLen = m_strTitle.size() * 2 / 3 + 1 + m_strContent.size();
    int textAnchX = anchX + (int)floor((m_iWidth - contentLen) / 2.0);
    int textAnchY = anchY + (int)floor(m_iHeight / 2.0);
    gotoPoint(textAnchX, textAnchY);
    colorPrint(m_strTitle + ":", m_iColor, m_iTitleColor);
    colorPrint(m_strContent, m_iColor, m_iContentColor);
    
    /* 刷新输出缓存 */
    cout.flush();
}
