#ifndef __POINT_H_
#define __POINT_H_

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Point
{
private:
    T xpos, ypos;
public:
    Point(T x=0, T y=0);
    template <class _T> friend ostream& operator<<(ostream& os, const Point<_T>& pos);
};

// template <class T>
// ostream& operator<<(ostream& os, const Point<T>& pos);

#endif