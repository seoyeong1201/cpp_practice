#include <iostream>
using namespace std;

class Number
{
private:
    int num;
public:
    Number(int n) : num(n) {}
    void ShowData() { cout<<num<<endl; }

    // int * operator->() const//const함수로 하니까 const int*로만 반환 가능, 클래스일 때는 아니잖아?
    // {
    //     return num;
    // }
    // const Number * operator->() const
    // {
    //     return this;
    // }
    const int& operator*() const
    {
        return num;
    }

    Number& operator*() 
    {
        return *this;
    }
};

int main(void)
{
    Number num(20);
    num.ShowData();

    // (*num)=30;
    // num->ShowData();
    // (*num).ShowData();

    Number num2(1);
    // cout<<(*num2)<<endl;

    return 0;
}