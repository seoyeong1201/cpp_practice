#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char * str;
public:
    String()
    {
        str=NULL;
    }
    String(const char * strIn)
    {
        int len=strlen(strIn)+1;
        str=new char[len];
        strcpy(str, strIn);
    }
    String(const String& strIn) //const? &없으면 const 안돼?
    {
        str=new char[strlen(strIn.str)+1];
        strcpy(str, strIn.str);
    }
    String& operator=(const String& strIn)
    {
        if(str!=NULL)
            delete[] str;
        str=new char[strlen(strIn.str)+1];
        strcpy(str, strIn.str);

        return *this;
    }
    ~String()
    {
        if(str!=NULL)
            delete[] str;
    }
    String& operator+(const String& str2) //언제 반환형에 &붙이고 언제 안붙이는거지?
    { 
        int len=strlen(str)+strlen(str2.str)+1;
        char* temp;
        temp=new char[len];
        strcpy(temp, str);
        strcat(temp, str2.str);
        String* newString=new String(temp); //동적할당할지말지는 선택 차이?
        delete[] temp;

        return *newString;
    }
    bool operator==(const String& str2)
    {
        if (strcmp(str, str2.str)==0) return true;
        else return false;
    }
    void operator+=(const String& str2) //return 해야하나?
    {
        *this=(*this)+str2;
    }

    friend ostream& operator<<(ostream& os, const String& str);
    friend istream& operator>>(istream& is, String& str);
};
    ostream& operator<<(ostream& os, const String& str)
    {
        os<<str.str;
        return os;
    }
    istream& operator>>(istream& is, String& str)
    {
        int maxLen=100;
        char temp[maxLen];
        is.getline(temp, maxLen);
        str.str=new char[strlen(temp)+1];
        strcpy(str.str, temp);

        return is;
    }

int main(void)
{
    String str1="I like ";
    String str2="string class";
    String str3=str1+str2;

    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;

    str1+=str2;
    // cout<<str1<<endl;
    // cout<<str2<<endl;
    // cout<<str3<<endl;
    if(str1==str3)
        cout<<"same string!"<<endl;
    else
        cout<<"not same string!"<<endl;
    
    String str4;
    cout<<"Enter string: ";
    cin>>str4;
    cout<<"You entered: "<<str4<<endl;

    return 0;
}