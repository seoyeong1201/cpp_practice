#include <iostream>
using namespace std;

void Divide(int num1, int num2)
{
    try
    {
        if(num2==0) throw 0;
        cout<<"Devision "<<num1/num2<<endl;
        cout<<"Remainder"<<num1%num2<<endl;
    }
    catch(char a)
    {
        cout<<"fist catch expn: "<<endl;
        throw;
    }
    
}

int main(void)
{
    try
    {
        throw;
    }
    catch(int expn)
    {
        cout<<"Second catch expn : "<<expn<<endl;
    }
    return 0;
}