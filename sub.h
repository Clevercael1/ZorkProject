#ifndef SUB_H
#define SUB_H
#include "super.h"
#include <string>

using namespace std; //namespace

class sub : super
{
public:
    string s;
    sub() : s("This class is to show inherritance, its super class shows a pure virtual function"){}
    string toString() {return s;}

};

#endif // SUB_H
