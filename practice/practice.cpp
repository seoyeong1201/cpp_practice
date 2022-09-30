#include <iostream>
using namespace std;

class AAA
{
private:
    int num;
public:
    AAA(int n=0): num(n)
    {
        cout<<"AAA(int n=0)"<<endl;
        cout<<"num : "<<num<<endl;
        cout<<this<<endl;
    }
    AAA(const AAA& ref): num(ref.num)
    {
        cout<<"AAA(const AAA& ref)"<<endl;
    }
    AAA& operator=(const AAA& ref)
    {
        num=ref.num;
        cout<<"operator=(const AAA& ref)"<<endl;
        return *this;
    }
    void checkAddress()
    {
        cout<<"A address : "<<this<<endl;
    }
};

class CCC
{
private:
    AAA mem;
public:
    CCC(const AAA& ref) 
    { 
        mem=ref; 
        cout<<"CCC generation"<<endl;
    }
    void checkAddress(AAA& ref)
    {
        mem.checkAddress();
        cout<<"C address : "<<this<<endl;
    }
};

int main(void)
{
    AAA obj1(12);
    cout<<"*************************"<<endl;
    CCC obj3(obj1);
    cout<<"*************************"<<endl;
    // obj3.checkAddress(obj1);

    return 0;
}