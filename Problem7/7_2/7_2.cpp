#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
    char * name;
    int age;
public:
    MyFriendInfo(char * myName, int myAge) : age(myAge)
    {
        name = new char[strlen(myName)+1];
        strcpy(name, myName);
    }
    void ShowMyFriendInfo()
    {
        cout<<"이름 : "<<name<<endl;
        cout<<"나이 : "<<age<<endl;
    }
    ~MyFriendInfo()
    {
        delete []name;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char * addr;
    char * phone;
public:
    MyFriendDetailInfo(char * myName, int myAge, char * myAddr, char * myPhone) : MyFriendInfo(myName, myAge)
    {
        addr = new char[strlen(myAddr)+1];
        phone = new char[strlen(myPhone)+1];
        strcpy(addr, myAddr);
        strcpy(phone, myPhone);
        
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout<<"주소 : "<<addr<<endl;
        cout<<"전화 : "<<phone<<endl;
    }
    ~MyFriendDetailInfo()
    {
        delete []addr;
        delete []phone;
    }
};

int main(void)
{
    MyFriendDetailInfo frd1("차수빈",27,"양산","010-0000-0000");
    frd1.ShowMyFriendDetailInfo();
    
    return 0;
}