#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(void)
{
    char stringPtr[25]="Google Korea";
    char *stringPtrTot="Google Korea My Dream";
    char stringPtr2[30];
    char *stringPtr3=" My Dream";

    cout<<"The string length is "<<strlen(stringPtr)<<endl;
    strcat(stringPtr," My Dream"); //cat도 크기 되는지 확인할 것
    // strcat(stringPtr,stringPtr3);
    cout<<stringPtr<<endl;
    strncpy(stringPtr2,stringPtr,sizeof(stringPtr)); //copy할 때는 크기 되는지 확인할 것
    cout<<stringPtr2<<endl;
    cout<<stringPtr<<endl;
    cout<<"The string length is "<<strlen(stringPtr2)<<endl;
    cout<<"The string length is "<<strlen(stringPtr)<<endl;
    cout<<"Is same? "<<strcmp(stringPtr,stringPtrTot)<<endl;

    cout<<string(30,'-')<<endl;
    cout<<"1 : "<<rand()<<endl;
    srand(0);
    cout<<"2 : "<<rand()<<endl;
    srand(1);
    cout<<"3 : "<<rand()<<endl;
    srand(1);
    cout<<"4 : "<<rand()<<endl;
    srand(time(NULL));
    cout<<"5 : "<<rand()%100<<endl;



    return 0;
}