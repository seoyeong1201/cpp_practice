#include <iostream>
using namespace std;

// //Problem 1
// int main(void){
//     int num[5];

//     int sum=0;
//     for(int i=0;i<5;i++){
//         cout<<i+1<<"번째 정수 입력: ";
//         cin>>num[i];
//         sum+=num[i];
//     }

//     cout<<"합계: "<<sum<<endl;

//     return 0;
// }

// //Problem 2
// int main(void)
// {
//     char name[7];
//     char phone[14];
//     cout<<"이름을 입력하시오: ";
//     cin>>name;
//     cout<<"전화번호를 입력하시오: ";
//     cin>>phone;

//     cout<<"이름: "<<name<<endl;
//     cout<<"전화번호: "<<phone<<endl;
//     cout<<sizeof(name)<<" "<<sizeof(phone)<<endl;
    
//     return 0;
// }

// //Problem 3
// int main(void)
// {   
//     int num;
//     cin>>num;

//     for (int i=1;i<10;i++)
//     {
//         cout<<num<<"x"<<i<<"="<<num*i<<endl;
//     }

//     return 0;
// }

//Problem 4
int main(void)
{
    while(true)
    {
        int salesPrice;
        cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
        cin>>salesPrice;
        if(salesPrice==-1){
            cout<<"프로그램을 종료합니다."<<endl;
            break;
        }
        else {
            cout<<"이번 달 급여: "<<50+salesPrice*0.12<<"만원"<<endl;
        }
    }
    return 0;
}