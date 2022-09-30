#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN=20;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

namespace creditGrade{
    enum {classA=7,classB=4,classC=2};
}

enum {NORMAL=1,HIGHCREDIT=2};

/*
Account class
entity class
*/
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
    Account(const Account & acc) //조심할 것!!! deep copy!!
    :accID(acc.accID), balance(acc.balance)
    {
        cusName=new char[strlen(acc.cusName)+1];
        strcpy(cusName,acc.cusName);
    }
    int GetID(void) const
    {
        return accID;
    }
    virtual void DepositMoney(int money)
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
    virtual ~Account()
    {
        delete []cusName;
    }

};


class NormalAccount : public Account
{
private:
    const int ratio;
public:
    NormalAccount(int accID, int balance, char* cusName, int ratio) 
    : Account(accID, balance, cusName), ratio(ratio)
    {}
    void DepositMoney(int money)
    {
        Account::DepositMoney(money);
        Account::DepositMoney((int)(money*ratio/100));
    }
};

class HighCreditAccount : public NormalAccount
{
private:
    int credit;
public:
    HighCreditAccount(int accID, int balance, char* cusName, int ratio, int credit)
    : NormalAccount(accID, balance, cusName, ratio), credit(credit)
    {}
    void DepositMoney(int money)
    {
        NormalAccount::DepositMoney(money);
        Account::DepositMoney(money*credit/100);
    }
};

/*
AccountHandler class
Control class
*/
class AccountHandler
{
private:
    Account * accPnt[100];
    int accNum;
public:
    AccountHandler() : accNum(0)
    {}

    void ShowMenu(void) const
    {
        cout<<"-----Menu-----"<<endl;
        cout<<"1. 계좌개설"<<endl;
        cout<<"2. 입 금"<<endl;
        cout<<"3. 출 금"<<endl;
        cout<<"4. 계좌정보 전체 출력"<<endl;
        cout<<"5. 프로그램 종료"<<endl;
    }

    void MakeNormalAccount(void)
    {
        int id;
        char name[NAME_LEN];
        int balance;
        int interest;

        cout<<"[보통예금계좌 개설]"<<endl;
        cout<<"계좌ID: "; cin>>id;
        cout<<"이 름: "; cin>>name;
        cout<<"입금액: "; cin>>balance;
        cout<<"이자율: "; cin>>interest;
        cout<<endl;
        accPnt[accNum++]=new NormalAccount(id,balance,name,interest);
    }

    void MakeHighCreditAccount(void)
    {
        int id;
        char name[NAME_LEN];
        int balance;
        int interest;
        int credit;

        cout<<"[신용신뢰계좌 개설]"<<endl;
        cout<<"계좌ID: "; cin>>id;
        cout<<"이 름: "; cin>>name;
        cout<<"입금액: "; cin>>balance;
        cout<<"이자율: "; cin>>interest;
        cout<<"신용등급(1toA, 2toB, 3toC): "; cin>>credit;
        cout<<endl;

        switch(credit)
        {
            case 1: accPnt[accNum++]=new HighCreditAccount(id,balance,name,interest,creditGrade::classA); break;
            case 2: accPnt[accNum++]=new HighCreditAccount(id,balance,name,interest,creditGrade::classB); break;
            case 3: accPnt[accNum++]=new HighCreditAccount(id,balance,name,interest,creditGrade::classC); break;
            default: cout<<"Wrong credit input"<<endl; return;
        }
    }

    void MakeAccount(void)
    {
        int account;

        cout<<"[계좌종류선택]"<<endl;
        cout<<"1.보통예금계좌 2.신용신뢰계좌"<<endl<<"선택: "; cin>>account;
        
        switch(account)
        {
            case NORMAL:
                MakeNormalAccount();
                break;
            case HIGHCREDIT:
                MakeHighCreditAccount();
                break;
            default:
                cout<<"Wrong Account"<<endl;
                break;
        }
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
    ~AccountHandler()
    {
        for(int i=0; i<accNum; i++)
        {
            delete accPnt[i];
        }
    }
};

int main(void)
{
    int choice;
    AccountHandler accHandler;

    while(1)
    {
        accHandler.ShowMenu();
        cout<<"선택: ";
        cin>>choice;
        cout<<endl;

        switch (choice)
        {
        case MAKE:
            accHandler.MakeAccount();
            break;
        case DEPOSIT:
            accHandler.DepositMoney();
            break;
        case WITHDRAW:
            accHandler.WithdrawMoney();
            break;
        case INQUIRE:
            accHandler.ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout<<"Illegal selection.."<<endl;
        }
    }
    return 0;
}

