#ifndef __TEMPLATE_H_
#define __TEMPLATE_H_

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class BoundCheckArray
{
private:
    T* arr;
    int arrlen;
    BoundCheckArray(const BoundCheckArray& arr);
    BoundCheckArray& operator=(const BoundCheckArray& arr);
public:
    BoundCheckArray(int len);
    T& operator[](int idx);
    T operator[] (int idx) const;
    int GetArrLen() const;
    ~BoundCheckArray();
};

template <class T>
void ShowAllData(const BoundCheckArray<T>& ref);
#endif