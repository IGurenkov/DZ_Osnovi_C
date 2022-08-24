/*
1. Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя. 
Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран. 
Не забыть освободить память. =) Разбить программу на функции.
2. Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand. Вывести на экран. 
Разбейте вашу программу на функции которые вызываются из main.
3. Написать программу, которая создаст два текстовых файла (*.txt), примерно по 50-100 символов в каждом 
(особого значения не имеет с каким именно содержимым). Имена файлов запросить у польлзователя.
4* Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).
5* Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово 
в указанном пользователем файле (для простоты работаем только с латиницей). Используем функцию find которая есть в строках std::string.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Задание 1

int Array(int Arr[], const size_t SIZE)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        Arr[i] = (2 << (i - 1));
        cout << Arr[i] << " ";
    }
    cout << endl;
    return 0;
}
// Задание 2

int Array2(int** Arr2, const size_t SIZE1, const size_t SIZE2)
{
    Arr2 = new int* [SIZE1];
    for (size_t i = 0; i < SIZE1; i++)
    {
        Arr2[i] = new int[SIZE2];
    }

    Arr2[0][0] = rand() % 100;
    Arr2[SIZE1 - 1][SIZE2 - 1] = rand() % 100;

    for (size_t i = 0; i < SIZE1; i++)
    {
        for (size_t j = 0; j < SIZE2; j++)
        {
            Arr2[i][j] = rand() % 100;
            cout << Arr2[i][j] << " ";
        }
        cout << endl;
    }
    for (size_t i = 0; i < SIZE1; i++)
    {
        delete[] Arr2[i];
    }
    delete[] Arr2;
    Arr2 = nullptr;
    cout << endl;
    return 0;
}

int main()
{
    // Задание 1
    cout << "ZADANIE 1";
    cout << endl << endl;

    int n;
    cout << "Enter size of your array: ";
    cin >> n;
    int* ptrArr = new int[n];

    if (n > 0)
    {
        ptrArr = new (nothrow) int[n];
        if (ptrArr != nullptr)
        {
            ptrArr[0] = 100;
            Array(ptrArr, n);
            cout << endl;
            cout << "ptrArr[0] = " << ptrArr[0];

            delete[] ptrArr;
            ptrArr = nullptr;
        }
        else
        {
            cout << "Error! Can not allocate memory!";
        }
    }
    cout << endl << endl;
    
    // Задание 2
    cout << "ZADANIE 2";
    cout << endl << endl;

    int** ptrArr2 = { 0 };
    const size_t a = 4;
    const size_t b = 4;
    Array2(ptrArr2, a, b);

        
    // Задание 3
    cout << "ZADANIE 3";
    cout << endl << endl;

    for (int i = 1; i < 2; i++)
    {	cin.clear();
        cin.ignore();
        cout << "Enter the name of file 001 with extension: ";
        string name1;
        getline (cin, name1);
        ofstream fout(name1);
        if (!fout.is_open())
        {
            cout << "File open ERROR!";
        }
        else
        {
            cout << "Enter the TEXT: ";
            string FileData;
            getline (cin, FileData);
            fout << FileData;
        }

        fout.close();
    }

    for (int j = 1; j < 2; j++)
    {
        cout << "Enter the name of file 002 with extension: ";
        string name2;
        getline (cin, name2);
        ofstream fout(name2);
        if (!fout.is_open())
        {
            cout << "File open ERROR!";
        }
        else
        {
            cout << "Enter the TEXT: ";
            string FileData2;
            getline (cin, FileData2);
            fout << FileData2;
        }
        fout.close();
    }
    cout << endl;
    
    // Задание 4
    cout << "ZADANIE 4";
    cout << endl << endl;

    for (int i = 1; i < 2; i++)
    {
        cout << "Enter the name of file 001 with extension for riding and rewriting: ";
        string name3;
        getline (cin, name3);
        ifstream fin(name3);
        if (!fin.is_open())
        {
            cout << "File open ERROR!";
        }
        else
        {
            getline (fin, name3);
            for (int i = 1; i < 2; i++)
            {
                ofstream fout("NewFile.txt", ofstream::app);
                if (!fout.is_open())
                {
                    cout << "File open ERROR!";
                }
                else
                {
                    fout << name3 << endl;
                }
                fout.close();
            }
        }
        fin.close();
    }

    for (int j = 1; j < 2; j++)
    {
        cout << "Enter the name of file 002 with extension for riding and rewriting: ";
        string name4;
        getline (cin, name4);
        ifstream fin(name4);
        if (!fin.is_open())
        {
            cout << "File open ERROR!";
        }
        else
        {
            getline (fin, name4);
            for (int i = 1; i < 2; i++)
            {
                ofstream fout("NewFile.txt", ofstream::app);
                if (!fout.is_open())
                {
                    cout << "File open ERROR!";
                }
                else
                {
                    fout << name4 << endl;
                }
                fout.close();
            }
        }
        fin.close();
    }
    cout << endl;
    //Задание 5
    
    cout << "ZADANIE 5";
    cout << endl << endl;

    string search;
    string line;
    ifstream Myfile;
    string NameOfFile;
    cout << "Enter the name of the file with extension: ";
    getline (cin, NameOfFile);
    Myfile.open(NameOfFile);
    cout << "Enter the word for searching: ";
    cin >> search;

    if (Myfile.is_open())
    {
        while (!Myfile.eof())
        {
            getline(Myfile, line);
            if ((line.find(search, 0)) != string::npos)
            {
                cout << "Yes we found: " + search;
            }            
        }
        Myfile.close();
    }
    else
    {
        cout << "File open ERROR!";
    }       
    cout << endl << endl;
    return 0;
}

