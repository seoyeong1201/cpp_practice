#include <iostream>
#include "Point.h"

template <class T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y) {}

template <class T>
ostream& operator<<(ostream& os, const Point<T>& pos)
{
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']';
    return os;
}
