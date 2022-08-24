#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "mylib.h"

using namespace std;
/*
1. Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib 
объявить 3 функции: для инициализации массива (типа float), печати его на экран и подсчета количества 
отрицательных и положительных элементов. Вызывайте эти 3-и функции из main для работы с массивом.
2. Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное 
с клавиатуры) в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) и 
возвращает true или false, вывести на экран «true» или «false».
3. Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. 
Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком). 
Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.
4* Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью 
директивы pragma pack. Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее 
на экран и ее размер с помощью sizeof. Сохраните эту структуру в текстовый файл.
5* Сделайте задание 1 добавив свой неймспейс во втором модуле (первое задание тогда можно не делать).*/

//Задание 2
#define SRAV(a, b) (a >= 0 && a < b ? c : d)
//Задание 3
#define SIZE 5
#define Swap(x, y) auto temp = Arr[j]; Arr[j] = Arr[j + 1]; Arr[j + 1] = temp

void sortirovka(int Arr[], size_t size, int a)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                Swap(x, y);
            }
        }
    }
}
 //Задание 4
struct SOTRUDNIK1
{
    unsigned short AGE;
    unsigned int ZARPLATA;
    string NAME;
    string ID;
};

#pragma pack(push, 1)
struct SOTRUDNIK2
{
    unsigned short AGE;
    unsigned int ZARPLATA;
    string NAME;
    string ID;
};
#pragma pack(pop)

int main()
{
    //Задание 2
    cout << "ZADANIE 2" << endl << endl;
    bool c = true;
    bool d = false;
    int a;
    cout << "VVEDITE CHISLO DLYA SRAVNENIYA: ";
    cin >> a;
    int b;
    cout << "VVEDITE DO KAKOGO CHISLA SRAVNIVATb: ";
    cin >> b;
    cout << boolalpha << "RESULTAT: " << SRAV(a, b, c, d);
    cout << endl << endl;

    //Задание 3
    cout << "ZADANIE 3" << endl << endl;

    int ARR[SIZE] = {};
    
    int* ptrArr1 = new int[SIZE];

    if (SIZE > 0)
    {
        ptrArr1 = new (nothrow) int[SIZE];
        if (ptrArr1 != nullptr)
        {
            ptrArr1[0] = 100;
            
            cout << "VVEDITE ELEMENTbI MASSIVA: ";
            for (int i = 0; i < SIZE; i++)
            {
                cin >> ARR[i];
            }
            cout << endl;

            delete[] ptrArr1;
            ptrArr1 = nullptr;
        }
        else
        {
            cout << "Error! Can not allocate memory!";
        }
    }   

    cout << "MASSIV DO SORTIROVKI: ";
    for (int i = 0; i < SIZE; i++)
    {        
        cout << ARR[i] << " ";
    }
    
    int temp = {};
    sortirovka(ARR, SIZE, temp);

    cout << endl << endl;
    cout << "MASSIV POSLE SORTIROVKI: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << ARR[i] << " ";
    }
    cout << endl << endl;

    //Задание 4
    cout << "ZADANIE 4" << endl << endl;

    SOTRUDNIK2* pS2 = new SOTRUDNIK2;
    
    pS2->AGE = 28;
    pS2->ZARPLATA = 44'000;
    pS2->NAME = "Vladimir";
    pS2->ID = "1234567";

    cout << "Vozrast: " << pS2->AGE << endl << "Zarplata: " << pS2->ZARPLATA 
        << endl << "Imya: " << pS2->NAME << endl << "Nomer: " << pS2->ID << endl << endl;

    cout << "RAZMER STRUCTURbI DO VbIRAVNIVANIYA: " << sizeof(SOTRUDNIK1) << endl;
    cout << "RAZMER STRUCTURbI POSLE VbIRAVNIVANIYA: " << sizeof(SOTRUDNIK2) << endl << endl;
        
    for (int i = 1; i < 2; i++)
    {        
        string name1 = "STRUCTURA.txt";        
        ofstream fout(name1);
        if (!fout.is_open())
        {
            cout << "File open ERROR!";
        }
        else
        {            
            fout << "Vozrast: " << pS2->AGE << endl;
            fout << "Zarplata: " << pS2->ZARPLATA << endl;
            fout << "Imya: " << pS2->NAME << endl;
            fout << "Nomer: " << pS2->ID << endl;
            fout << "Razmer structurbl: " << sizeof(SOTRUDNIK2) << endl;
        }
        fout.close();
    }    
    delete pS2;

    //Задание 5 + Задание 1    
    cout << "ZADANIE 5 + ZADANIE 1" << endl << endl;

    const size_t XX = 5;
    float Arr2[XX];
    int count = 0;

    int* ptrArr = new int[XX];

    if (XX > 0)
    {
        ptrArr = new (nothrow) int[XX];
        if (ptrArr != nullptr)
        {
            ptrArr[0] = 100;
            MyArray::Array(Arr2, XX);
            cout << endl;            

            delete[] ptrArr;
            ptrArr = nullptr;
        }
        else
        {
            cout << "Error! Can not allocate memory!";
        }
    }
        
    Output(Arr2, XX);
    cout << endl << endl;
    Schet(Arr2, XX, count);
    cout << endl << endl;

    return 0;
}

