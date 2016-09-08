#ifndef BASE_H
#define BASE_H

#include <vector>
using namespace std;

class Base {
 public:
    Base() {};
    ~Base() {};
    
 protected:
    void * m_pParent;
    vector<void *> *m_pChilds;
    int m_iChildCount;
};

#endif
