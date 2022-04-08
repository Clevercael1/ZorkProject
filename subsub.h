#ifndef SUBSUB_H
#define SUBSUB_H
#include "sub.h"
#include <string>

using namespace std;

class subsub : sub
{
public:
    subsub();
    string toString() {return "This class is to show multiple inherritance";}
};

#endif // SUBSUB_H
