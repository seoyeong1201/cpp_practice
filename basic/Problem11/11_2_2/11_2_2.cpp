#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
    int * array;
    int arrlen;
    BoundCheckIntArray(const BoundCheckIntArray& ref) {}
    BoundCheckIntArray& operator=(const BoundCheckIntArray& ref) {}
public:
    BoundCheckIntArray(int len) : arrlen(len)
    {
        array=new int[len];
    }
    int& operator[](int idx)
    {
        if(idx<0 || idx>=arrlen)
        {
            cout<<"Out of index"<<endl;
            exit(1);
        }
        return array[idx];
    }
    ~BoundCheckIntArray()
    {
        delete[] array;
    }
};

class BoundCheck2DIntArray
{
private:
    BoundCheckIntArray** array;
    int arrlen;

    BoundCheck2DIntArray(const BoundCheck2DIntArray& ref) {}
    BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& ref) {}
public:
    BoundCheck2DIntArray(int x, int y) : arrlen(x)
    {
        array=new BoundCheckIntArray*[x];
        for (int i=0; i<x; i++)
        {
            array[i]=new BoundCheckIntArray(y);
        }
    }
    BoundCheckIntArray& operator[](int idx)
    {
        if(idx<0 || idx>=arrlen)
        {
            cout<<"Wrong index"<<endl;
            exit(1);
        }
        return *(array[idx]);
    }
    ~BoundCheck2DIntArray()
    {
        for (int i=0; i<arrlen; i++)
        {
            delete array[i];
        }
        delete[] array;
    }
};

int main(void)
{
    BoundCheck2DIntArray arr2d(3, 4);

    for(int n=0; n<3; n++)
        for(int m=0; m<4; m++)
            arr2d[n][m]=n+m;
    
    for(int n=0; n<3; n++)
    {
        for(int m=0; m<4; m++)
            cout<<arr2d[n][m]<<' ';
        cout<<endl;
    }

    return 0;
}
