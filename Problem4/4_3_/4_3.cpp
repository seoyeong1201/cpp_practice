#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum
    {
        CLERK,
        SENIOR,
        ASSIST,
        MANAGER
    };

    void ShowPositionInfo(int rank)
    {
        switch(rank)
        {
            case COMP_POS::CLERK:
                cout<<"사원"<<endl;
                break;
            case COMP_POS::SENIOR:
                cout<<"주임"<<endl;
                break;
            case COMP_POS::ASSIST:
                cout<<"대리"<<endl;
                break;
            case COMP_POS::MANAGER:
                cout<<"과장"<<endl;
                break;
        }
    }
}

class NameCard
{
private:
    char * name;
    char * companyName;
    char * phoneNumber;
    int rank;
public:
    NameCard(char* name, char* compName, char* phoneNum, int rank)
    :rank(rank)
    {
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->companyName=new char[strlen(compName)+1];
        strcpy(this->companyName,compName);
        this->phoneNumber=new char[strlen(phoneNum)+1];
        strcpy(this->phoneNumber,phoneNum);
    }
    void ShowNameCardInfo()
    {
        cout<<"이름: "<<name<<endl;
        cout<<"회사: "<<companyName<<endl;
        cout<<"전화번호: "<<phoneNumber<<endl;
        cout<<"직급: "; COMP_POS::ShowPositionInfo(rank);
        cout<<endl;
    }
    ~NameCard()
    {
        delete []name;
        delete []companyName;
        delete []phoneNumber;
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}