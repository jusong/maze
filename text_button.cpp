#include <iostream>
#include <sstream>

#include "text_button.h"

using namespace std;


TextButton::TextButton(string &_title, string &_content) {
    m_strTitle = _title;
    m_strContent = _content;
}

TextButton::TextButton(string &_title, int content) {
    m_strTitle = _title;

    stringstream stream;
    stream << _content >> m_strContent;
}

void TextButton::setTitleColor(int _title_color) {
    m_iTitleColor = _title_color;
}

void TextButtion::setContentColor(int _content_color) {
    m_iContentColor = _content_color;
}
