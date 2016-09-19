#ifndef TEXT_BUTTON_H
#define TEXT_BUTTON_H

#include "base.h"

class TextButton : public Base {
 public:
    TextButton(const string &_title = "", int _content = 0);
    TextButton(const TextButton &_textbtn);
    void setTitle(const string &_title);
    void setContent(const int _content);
    void addContent(const int _content);
    void setTitleColor(const int _title_color);
    void setContentColor(const int _content_color);

    string getTitle() const;
    int getContent() const;
    int getTitleColor() const;
    int getContentColor() const;
    
    void printSelf() const;

 private:
    string m_strTitle;		//标题
    int m_iContent;			//内容
    int m_iTitleColor;		//标题颜色
    int m_iContentColor;	//内容颜色
};

#endif
