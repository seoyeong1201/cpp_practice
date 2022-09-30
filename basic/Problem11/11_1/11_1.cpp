#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;
public:
    Gun(int bnum) : bullet(bnum)
    {}
    void Shot()
    {
        cout<<"BBANG!"<<endl;
        bullet--;
    }
};

class Police
{
private:
    int handcuffs;
    Gun * pistol;
public:
    Police(int bnum, int bcuff) : handcuffs(bcuff)
    {
        if(bnum>0)
            pistol=new Gun(bnum);
        else
            pistol=NULL;
    }
    Police(const Police& pman)
    {
        handcuffs=pman.handcuffs;
        if (pman.pistol==NULL) pistol=NULL;
        else pistol=new Gun(*(pman.pistol));
    }
    Police& operator=(const Police& pman)
    {
        handcuffs=pman.handcuffs;
        if (pistol!=NULL)
            delete pistol;
        if (pman.pistol==NULL) pistol=NULL;
        else pistol=new Gun(*(pman.pistol));

        return *this;
    }
    void PutHandcuff()
    {
        cout<<"SNAP!"<<endl;
        handcuffs--;
    }
    void Shot()
    {
        if(pistol==NULL)
            cout<<"Hut BBANG!"<<endl;
        else
            pistol->Shot();
    }
    ~Police()
    {
        if(pistol!=NULL)
            delete pistol;
    }
};

int main(void)
{
    Police pman1(0, 3);
    pman1.Shot();
    pman1.PutHandcuff();
    Police pman2(pman1);
    Police pman3(0,2);

    pman3=pman1;
    pman2.Shot();
    pman2.PutHandcuff();
    pman3.Shot();
    pman3.PutHandcuff();

    return 0;
}