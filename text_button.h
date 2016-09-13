#ifndef TEXT_BUTTON_H
#define TEXT_BUTTON_H

#include "base.h"

class TextButton : public Base {
 public:
    TextButton(const string &_title = "", const string &content = "");
    void setTitle(const string &_title);
    void setContent(const string &_content);
    void setTitleColor(int _title_color);
    void setContentColor(int _content_color);
    void printSelf() const;
    void print() const;

 private:
    string m_strTitle;		//标题
    string m_strContent;	//内容
    int m_iTitleColor;		//标题颜色
    int m_iContentColor;	//内容颜色
};

#endif
