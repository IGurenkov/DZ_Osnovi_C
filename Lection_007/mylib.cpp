#include <iostream>
#include <fstream>
#include <string>
using namespace std;


namespace MyArray
{
    int Array(float Arr[], const size_t SIZE2)
    {
        cout << "VVEDITE ELEMENTbI MASSIVA: ";
        for (int i = 0; i < SIZE2; i++)
        {
            cin >> Arr[i];
        }
        return 0;
    }
}

int Output (float Arr[], const size_t SIZE2)
{
    cout << "VASH MASSIV: ";
    for (int j = 0; j < SIZE2; j++)
    {        
        cout << Arr[j] << " ";
    }    
    return 0;    
}

int Schet(float Arr[], const size_t SIZE2, int a)
{
    for (int i = 0; i < SIZE2; i++)
    {
        if (Arr[i] < 0)
            a++;
    }
    cout << "KOLICHESTVO ELEMENTOV >0: " << a;
    return 0;
}