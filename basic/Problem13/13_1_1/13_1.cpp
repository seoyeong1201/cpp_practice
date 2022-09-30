#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    {}
    void ShowPosition() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
};

template <class T>
void SwapData(T& d1, T& d2)
{
    T temp;
    temp=d1;
    d1=d2;
    d2=temp;
}

template <class T>
T SumArray(T arr[], int len)
{
    T sum=0;
    for(int i=0; i<len; i++)
        sum+=arr[i];
    return sum; 
}

int main(void)
{
    Point pos1(1,2);
    Point pos2(3,4);
    pos1.ShowPosition();
    pos2.ShowPosition();
    SwapData<Point>(pos1, pos2);
    pos1.ShowPosition();
    pos2.ShowPosition();
    cout<<endl;

    int len=3;
    double arrayFloat[3]={2.1, 3.2, 3.3};
    cout<<SumArray<double>(arrayFloat, len)<<endl;

    int arr1[]={10, 20, 30};
    cout<<SumArray(arr1, sizeof(arr1)/sizeof(int))<<endl;

    return 0;
}