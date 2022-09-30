#include "calculator.h"
#include <iostream>
using namespace std;

void Calculator::Init()
{
    for(int i=0;i<4;i++){
        count[i]=0;
    }
}

float Calculator::Add(float a, float b){
    count[0]+=1;
    return a+b;
}

float Calculator::Min(float a, float b){
    count[1]+=1;
    return a-b;
}

float Calculator::Mul(float a, float b){
    count[2]+=1;
    return a*b;
}

float Calculator::Div(float a, float b){
    count[3]+=1;
    return a/b;
}

void Calculator::ShowOpCount(){
    cout<<"덧셈: "<<count[0]<<" 뺄셈: "<<count[1]<<" 곱셈: "<<count[2]<<" 나눗셈: "<<count[3]<<endl;
}