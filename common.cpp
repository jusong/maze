#include "common.h"


//字符串分割函数
vector<string> Common::split(const string str, const string pattern) {
    vector<string> result;
    string::size_type pos = 0;
    int patnLen = pattern.size();
    string s;
    int i = 0;
    do {
        pos = str.find(pattern, i);
        if(pos != string::npos) {
            s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos + patnLen;
        } else {
            s = str.substr(i);
            result.push_back(s);
        }
    } while(pos != string::npos);
        
    return result;
}
