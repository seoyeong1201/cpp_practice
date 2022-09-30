#ifndef _printer_h_
#define _printer_h_
#include <cstring>

class Printer{
private:
    // char* _string;
    char stringArray[100];

public:
    void SetString(char *str);
    void ShowString();

};

#endif