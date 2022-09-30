#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x, int y)
    :xpos(x),ypos(y)
    {}
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
    Circle(int x, int y, int r) : center(x,y), radius(r) {}
    void Init(int x, int y, int r)
    {
        center.Init(x,y);
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
    // Point innerCenter;
    // Point outerCenter;
public:
    Ring(int xInner, int yInner, int rInner, int xOuter, int yOuter, int rOuter)
    :innerCircle(xInner,yInner,rInner), outerCircle(xOuter,yOuter,rOuter)
    {
        // innerCircle(innerCenter,rInner);
        // outerCircle(outerCenter,rOuter);
    }
    void Init(int xInner, int yInner, int rInner, int xOuter, int yOuter, int rOuter)
    {
        // innerCenter.Init(xInner,yInner);
        // outerCenter.Init(xOuter,yOuter);
        innerCircle.Init(xInner,yInner,rInner);
        outerCircle.Init(xOuter,yOuter,rOuter);
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
    Ring ring(1,1,4,2,2,9);
    // ring.Init(1,1,4,2,2,9);
    ring.ShowRingInfo();
    return 0;
}