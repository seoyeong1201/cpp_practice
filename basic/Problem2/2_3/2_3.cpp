#include <iostream>
using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point & p1, const Point &p2){
    Point *add=new Point;
    add->xpos=p1.xpos+p2.xpos;
    add->ypos=p1.ypos+p2.ypos;
    return *add;
}

int main(void)
{
    Point* ptr1=new Point;
    Point* ptr2=new Point;
    ptr1->xpos=2;
    ptr1->ypos=1;
    ptr2->xpos=9;
    ptr2->ypos=4;

    Point &pnt=PntAdder(*ptr1,*ptr2);

    cout<<"x: "<<pnt.xpos<<", y: "<<pnt.ypos<<endl;

    delete ptr1;
    delete ptr2;
    delete &pnt;

    return 0;
}