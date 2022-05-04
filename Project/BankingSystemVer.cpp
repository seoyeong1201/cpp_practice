#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN=20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
private:
    int accID;
    int balance;
    char * cusName;
public:
    Account(int accID, int balance, char * cusName)
    :accID(accID), balance(balance)
    {
        this->cusName=new char[strlen(cusName)+1];
        strcpy(this->cusName, cusName);
    }
    Account(const Account & acc)
    :accID(acc.accID), balance(acc.balance)
    {
        cusName=new char[strlen(acc.cusName)+1];
        strcpy(cusName,acc.cusName);
    }
    int GetID(void) const
    {
        return accID;
    }
    void DepositMoney(int money)
    {
        balance+=money;
        cout<<"입금완료"<<endl<<endl;
    }
    void WithdrawMoney(int money)
    {
        if(balance<money)
        {
            cout<<"잔액부족"<<endl<<endl;
            return;
        }
        balance-=money;
        cout<<"출금완료"<<endl<<endl;
        return;
    }
    void ShowAccInfo(void) const
    {
        cout<<"계좌ID: "<<accID<<endl;
        cout<<"이 름: "<<cusName<<endl;
        cout<<"잔 액: "<<balance<<endl<<endl;
    }
    ~Account()
    {
        delete []cusName;
    }

};

Account* accPnt[100];
int accNum=0;

int main(void)
{
    int choice;

    while(1)
    {
        ShowMenu();
        cout<<"선택: ";
        cin>>choice;
        cout<<endl;

        switch (choice)
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithdrawMoney();
            break;
        case INQUIRE:
            ShowAllAccInfo();
            break;
        case EXIT:
            for(int i=0; i<accNum; i++) //important!!!
            {
                delete accPnt[i];
            }
            return 0;
        default:
            cout<<"Illegal selection.."<<endl;
        }
    }
}

void ShowMenu(void)
{
    cout<<"-----Menu-----"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입 금"<<endl;
    cout<<"3. 출 금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
}

void MakeAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;
    // char* namePnt;

    cout<<"[계좌개설]"<<endl;
    cout<<"계좌ID: "; cin>>id;
    cout<<"이 름: "; cin>>name;
    cout<<"입금액: "; cin>>balance;
    cout<<endl;
    // namePnt=new char[strlen(name)+1];
    // strcpy(namePnt,name);

    accPnt[accNum++]=new Account(id, balance, name);
    // accNum++;
}

void DepositMoney(void)
{
    int money;
    int id;
    cout<<"[입  금]"<<endl;
    cout<<"계좌ID: "; cin>>id;
    cout<<"입금액: "; cin>>money;

    for(int i=0; i<accNum; i++)
    {
        if(accPnt[i]->GetID()==id)
        {
            accPnt[i]->DepositMoney(money);
            return;
        }
    }
    cout<<"유효하지 않은 ID입니다."<<endl<<endl;
}

void WithdrawMoney(void)
{
    int money;
    int id;
    cout<<"[출  금]"<<endl;
    cout<<"계좌ID: "; cin>>id;
    cout<<"출금액: "; cin>>money;

    for(int i=0; i<accNum; i++)
    {
        if(accPnt[i]->GetID()==id)
        {
            accPnt[i]->WithdrawMoney(money);
            return;
        }
    }
    cout<<"유효하지 않은 ID입니다."<<endl<<endl;
}

void ShowAllAccInfo(void)
{
    for(int i=0; i<accNum; i++)
    {
        accPnt[i]->ShowAccInfo();
    }
}