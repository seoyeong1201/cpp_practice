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
        cout<<'['<<xpos<<", "<<ypos<<"]"<<endl;
    }
    friend Point operator+(const Point &pos1, const Point &pos2);
    friend Point operator-(const Point &pos1, const Point &pos2);
    friend bool operator==(const Point &pos1, const Point &pos2);
    friend bool operator!=(const Point &pos1, const Point &pos2);
    friend Point operator~(const Point &pos);

    friend ostream& operator<<(ostream&, const Point&);
    friend istream& operator>>(istream&, Point&);

    Point& operator+=(const Point &pos)
    {
        xpos+=pos.xpos;
        ypos+=pos.ypos;
        return *this;
    }
    Point& operator-=(const Point &pos)
    {
        xpos-=pos.xpos;
        ypos-=pos.ypos;
        return *this;
    }
    Point operator-()
    {
        Point pos(-xpos, -ypos);
        return pos;
    }

};

Point operator+(const Point &pos1, const Point &pos2)
{
    Point pos(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
    return pos;
}

Point operator-(const Point &pos1, const Point &pos2)
{
    Point pos(pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos);
    return pos;
}

bool operator==(const Point &pos1, const Point &pos2)
{
    if (pos1.xpos==pos2.xpos && pos1.ypos==pos2.ypos) return true;
    else return false;
}

bool operator!=(const Point &pos1, const Point &pos2)
{
    // if (operator==(pos1, pos2)) return false;
    // else return true;
    return !(pos1==pos2);
}

Point operator~(const Point &ref)
{
    Point pos(ref.ypos, ref.xpos);
    return pos;
}

// ostream& operator<<(ostream &os, Point &pos);
// istream& operator>>(istream &os, Point &pos);

int main(void)
{
    // Point pos1(3,4);
    // Point pos2(3,4);
    // Point pos3=pos1-pos2;

    // pos1.ShowPosition();
    // pos2.ShowPosition();
    // pos3.ShowPosition();

    // Point pos4(1,1);
    // pos1+=Point(-3,-4);
    // pos1.ShowPosition();
    // pos1-=pos4;
    // pos1.ShowPosition();

    // cout<<(pos1==pos2)<<endl;
    // cout<<(pos1!=pos2)<<endl;
    // cout<<(pos1==pos3)<<endl;
    // cout<<(pos1!=pos3)<<endl;

    // Point pos2=-pos1;
    // pos2.ShowPosition();
    // Point pos3=~pos1;
    // pos3.ShowPosition();
    // (-pos1).ShowPosition();

    Point pos1;
    cout<<"x, y 좌표 순으로 입력: ";
    cin>>pos1;
    cout<<pos1;

    Point pos2;
    cout<<"x, y 좌표 순으로 입력: ";
    cin>>pos2;
    cout<<pos2;

    return 0;
}

ostream& operator<<(ostream &os, const Point &pos)
{
    os<<"["<<pos.xpos<<", "<<pos.ypos<<"]"<<endl;
    return os;
}
istream& operator>>(istream &is, Point &pos)
{
    is>>pos.xpos>>pos.ypos;
    return is;
}