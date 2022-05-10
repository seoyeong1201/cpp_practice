#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char * title;
    char * isbn;
    int price;
public:
    Book(char * bTitle, char * bIsbn, int bPrice) : price(bPrice)
    {
        title = new char[strlen(bTitle)+1];
        isbn = new char[strlen(bIsbn)+1];
        strcpy(title, bTitle);
        strcpy(isbn, bIsbn);
    }
    void ShowBookInfo()
    {
        cout<<"제목: "<<title<<endl;
        cout<<"ISBN: "<<isbn<<endl;
        cout<<"가격: "<<price<<endl;
    }
    ~Book()
    {
        delete []title;
        delete []isbn;
    }
};

class Ebook : public Book
{
private: 
    char * DRMKey;
public:
    Ebook(char * eTitle, char * eIsbn, int ePrice, char * eDRMKey) : Book(eTitle, eIsbn, ePrice)
    {
        DRMKey = new char[strlen(eDRMKey)+1];
        strcpy(DRMKey, eDRMKey);
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout<<"인증키: "<<DRMKey<<endl;
    }
    ~Ebook()
    {
        delete []DRMKey;
    }
};

int main(void)
{
    Book book("good C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout<<endl;
    Ebook ebook("good C++ ebook", "555-12345-890-1", 10000, "fdx920i8kiw");
    ebook.ShowEBookInfo();
    return 0;
}