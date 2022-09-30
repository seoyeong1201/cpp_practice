#include <iostream>
using namespace std;

void swap(int* arg1, int* arg2);
void swap(char* arg1, char* arg2);
void swap(double* arg1, double* arg2);

int main(void)
{
    int num1=20, num2=30;
    swap(&num1, &num2);
    cout<<num1<<' '<<num2<<endl;

    char ch1='A', ch2='Z';
    swap(&ch1, &ch2);
    cout<<ch1<<' '<<ch2<<endl;

    double dbl1=1.111, dbl2=5.555;
    swap(&dbl1, &dbl2);
    cout<<dbl1<<' '<<dbl2<<endl;

    return 0;
}

void swap(int* arg1, int* arg2)
{
    int temp;
    temp=*arg1;
    *arg1=*arg2;
    *arg2=temp;
}

void swap(char* arg1, char* arg2)
{
    char temp;
    temp=*arg1;
    *arg1=*arg2;
    *arg2=temp;
}

void swap(double* arg1, double* arg2)
{
    double temp;
    temp=*arg1;
    *arg1=*arg2;
    *arg2=temp;
}