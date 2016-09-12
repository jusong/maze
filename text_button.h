#ifndef TEXT_BUTTON_H
#define TEXT_BUTTON_H

class TextButton : public Base {
 public:
    TextButton(string _title, string content);
    TextButton(string _title, int content);

 private:
    string m_strTitle;
    string m_strContent;
}
#endif
