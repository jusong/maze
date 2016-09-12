#ifndef TEXT_BUTTON_H
#define TEXT_BUTTON_H

class TextButton : public Base {
 public:
    TextButton(string &_title, string &content);
    TextButton(string &_title, int content);
    void setTitleColor(int _title_color);
    void setContentColor(int _content_color);

 private:
    string m_strTitle;
    string m_strContent;
    int m_iTitleColor;
    int m_iContentColor;
}
#endif
