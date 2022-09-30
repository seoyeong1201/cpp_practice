#include <iostream>
#include <cstring>
#include "printer.h"
using namespace std;

void Printer::SetString(char *str)
{
    strcpy(stringArray,str);
}

void Printer::ShowString()
{
    cout<<stringArray<<endl;
}
