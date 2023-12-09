#ifndef ENGINEWRAPPER_SUBJECT_H
#define ENGINEWRAPPER_SUBJECT_H

#include <math.h>

class Subject {
public:
    int f1(int a, int b, int c) { return a+b+c; }
    int f2(int a) { return pow(a,2); }
    int f3(int a, int b) { return a-b; }
};


#endif //ENGINEWRAPPER_SUBJECT_H
