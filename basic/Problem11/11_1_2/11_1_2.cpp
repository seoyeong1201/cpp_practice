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
    Book(char* title, char* isbn, int price) : price(price)
    {
        this->title=new char[strlen(title)+1];
        strcpy(this->title, title);
        this->isbn=new char[strlen(isbn)+1];
        strcpy(this->isbn, isbn);
    }
    Book(const Book& book) : price(book.price)
    {
        this->title=new char[strlen(book.title)+1];
        strcpy(this->title, book.title);
        this->isbn=new char[strlen(book.isbn)+1];
        strcpy(this->isbn, book.isbn);
    }
    Book& operator=(const Book& ref)
    {
        if (title!=NULL) delete[] title;
        if (isbn!=NULL) delete[] isbn;
        this->title=new char[strlen(ref.title)+1];
        strcpy(this->title, ref.title);
        this->isbn=new char[strlen(ref.isbn)+1];
        strcpy(this->isbn, ref.isbn);

        this->price=ref.price;

        return *this;
    }
    void ShowBookInfo()
    {
        cout<<"title: "<<title<<endl;
        cout<<"ISBN: "<<isbn<<endl;
        cout<<"price: "<<price<<endl;
    }
    ~Book()
    {
        delete[] title;
        delete[] isbn;
    }
};

class EBook : public Book
{
private:
    char * DRMKey;
public:
    EBook(char * title, char * isbn, int price, char * drmKey) : Book(title, isbn, price)
    {
        DRMKey=new char[strlen(drmKey)+1];
        strcpy(DRMKey, drmKey);
    }
    EBook(const EBook& ref) : Book(ref)
    {
        DRMKey=new char[strlen(ref.DRMKey)+1];
        strcpy(DRMKey, ref.DRMKey);
    }
    EBook& operator=(const EBook& ref)
    {
        Book::operator=(ref);
        if (DRMKey!=NULL) delete[] DRMKey;
        DRMKey=new char[strlen(ref.DRMKey)+1];
        strcpy(DRMKey, ref.DRMKey);

        return *this;
    }
    void ShowEBookInfo()
    {
        Book::ShowBookInfo();
        cout<<"AuthKey: "<<DRMKey<<endl;
    }
    ~EBook()
    {
        delete[] DRMKey;
    }
};

int main(void)
{
    Book book("good C++", "555-1234-890-0", 20000);
    book.ShowBookInfo();
    cout<<endl;
    Book book2(book);
    book2.ShowBookInfo();
    cout<<endl;
    Book book3("Hi", "0", 0);
    book3=book2;
    book3.ShowBookInfo();
    cout<<endl;

    EBook ebook("good C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    cout<<endl;
    EBook ebook2(ebook);
    ebook2.ShowEBookInfo();
    cout<<endl;
    EBook ebook3("Hi", "0", 0, "0");
    ebook3=ebook2;
    ebook3.ShowEBookInfo();
    cout<<endl;
    return 0;
}