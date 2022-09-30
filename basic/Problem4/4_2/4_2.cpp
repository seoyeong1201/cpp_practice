#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    void Init(int x, int y)
    {
        xpos=x;
        ypos=y;
    }
    void ShowPointInfo() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
};

class Circle
{
private:
    Point center;
    int radius;
public:
    void Init(Point ct, int r)
    {
        center=ct;
        radius=r;
    }
    void ShowCircleInfo() const
    {
        cout<<"radius : "<<radius<<endl;
        cout<<"center : ";
        center.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle innerCircle;
    Circle outerCircle;
    Point innerCenter;
    Point outerCenter;
public:
    void Init(int xInner, int yInner, int rInner, int xOuter, int yOuter, int rOuter)
    {
        innerCenter.Init(xInner,yInner);
        outerCenter.Init(xOuter,yOuter);
        innerCircle.Init(innerCenter,rInner);
        outerCircle.Init(outerCenter,rOuter);
    }
    void ShowRingInfo() const
    {
        cout<<"Inner Circle Info..."<<endl;
        innerCircle.ShowCircleInfo();
        cout<<"Outer Circle Info..."<<endl;
        outerCircle.ShowCircleInfo();
    }
};

int main(void)
{
    Ring ring;
    ring.Init(1,1,4,2,2,9);
    ring.ShowRingInfo();
    return 0;
}