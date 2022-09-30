#include <iostream>
#include "BoundCheckArray.h"
#include "BoundCheckArray.cpp"
#include "Point.h"
#include "Point.cpp"

int main(void)
{
    BoundCheckArray<int> arr1(5);
    for(int i=0; i<5; i++)
        arr1[i]=(i+1)*11;
    ShowAllData<int>(arr1);

    BoundCheckArray< Point<int> > arr2(3);
    arr2[0]=Point<int>(3, 4);
    arr2[1]=Point<int>(5, 6);
    arr2[2]=Point<int>(7, 8);
    // for(int i=0; i<arr2.GetArrLen(); i++)
    // {
    //     cout<<arr2[i];
    // }
    ShowAllData< Point<int> >(arr2);

    BoundCheckArray< Point<int>* > arr3(3);
    arr3[0]=new Point<int>(3, 4);
    arr3[1]=new Point<int>(5, 6);
    arr3[2]=new Point<int>(7, 8);
    for(int i=0; i<arr3.GetArrLen(); i++)
        cout<<*(arr3[i])<<endl;
    delete arr3[0];
    delete arr3[1];
    delete arr3[2];

    return 0;
}