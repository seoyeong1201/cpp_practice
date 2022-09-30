#include <iostream>
using namespace std;

int BoxVolume(int length, int width, int height);
int BoxVolume(int length, int width);
int BoxVolume(int length);

int main(void)
{
    cout<<"[3,3,3]: "<<BoxVolume(3,3,3)<<endl;
    cout<<"[5,5,D]: "<<BoxVolume(5,5)<<endl;
    cout<<"[7,D,D]: "<<BoxVolume(7)<<endl;
    
    return 0;
}

int BoxVolume(int length, int width, int height)
{
    return length*width*height;
}

int BoxVolume(int length, int width)
{
    return length*width*1;
}

int BoxVolume(int length)
{
    return length*1*1;
}