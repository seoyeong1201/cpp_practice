#include <iostream>
using namespace std;

//Problem 1
void increaseOne(int &num){
    num+=1;
}

void changeSign(int &num){
    num=-num;
}

void SwapPointer1(int *(&ptr1), int *(&ptr2)){
    int *temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

void SwapPointer2(int **dptr1, int **dptr2){
    int *temp = *dptr1;
    *dptr1 = *dptr2;
    *dptr2 = temp;
}

int main(void) {
    // int num1=2;
    // increaseOne(num1);
    // cout<<num1<<endl;

    // changeSign(num1);
    // cout<<num1<<endl;

    int num1=5;
    int *ptr1=&num1;
    int num2=10;
    int *ptr2=&num2;

    SwapPointer1(ptr1,ptr2);
    cout<<*ptr1<<" "<<*ptr2<<endl;
    SwapPointer2(&ptr1,&ptr2);
    cout<<*ptr1<<" "<<*ptr2<<endl;

    return 0;
}