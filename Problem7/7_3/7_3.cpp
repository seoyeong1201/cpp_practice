#include <iostream>
using namespace std;

class Rectangle
{
private:
    int width;
    int length;
public:
    Rectangle(int w, int l) : width(w), length(l)
    {}
    void ShowAreaInfo()
    {
        cout<<"면적 : "<<width*length<<endl;
    }
};

class Square : public Rectangle
{
public:
    Square(int a) : Rectangle(a,a)
    {}
};

int main(void)
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}