/*
1. Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер. Вызвать эту функцию из main.
2. Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в принятом 
массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.
3. Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. 
Вывести массив на экран.
4* Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным), при этом метод должен 
циклически сместить все элементы массива на n позиций.
5** Написать функцию, которой передается не пустой одномерный целочисленный массив, она должна вернуть истину если в массиве есть место, 
в котором сумма левой и правой части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false, 
checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив не входят.
*/

#include <iostream>
// Задание 1
    bool FunArr(double Arr[], int SIZE)
    {
        for (size_t i = 0; i < SIZE; i++)
        {
            std::cout << Arr[i] << " ";
        }
        std::cout << std::endl;
    return true;
    };

// Задание 2
    int main1(int Arr[], const size_t size)
    {
        for (int k = 0; k < size; k++)
        {
            std::cout << Arr[k] << " ";
        }
        std::cout << std::endl;
        for (int k = 0; k < size; k++)
        {
            if (Arr[k] != 0)
            {
                Arr[k] = 0;
            }
            else
            {
                Arr[k] = 1;
            }
        };
        return 0;
    }
    
// Задание 3
    int main2(int Arr[], const size_t size)
    {
        int len = size;
        int numbers = 1;
        for (int p = 0; p < len; p++)
        {
            Arr[p] = numbers;
            numbers = numbers + 3;
        };
        
        return 0;
    }

// Задание 4
    int sdvig(int Arr[], const size_t size, int k)
    {
        int t = Arr[size - 1];

        for (int i = size - 1; i > 0; i--)
        {
            Arr[i] = Arr[i - 1];
        }
        Arr[0] = t;
        return 0;
    }

    int sdvig2(int Arr[], const size_t size, int k)
    {
        int t = Arr[0];

        for (int i = 0; i < size - 1; i++)
        {
            Arr[i] = Arr[i + 1];
        }
        Arr[size - 1] = t;
        return 0;
    }

int main()
{
    // Задание 1
    std::cout << "ZADANIE 1" << std::endl;
    const int MYSIZE = 10;
    double MYARR[] = { 13.4678, 10.6768, 1.875, 4.6543, 3.6533, 65.678323, 88.7733, 2.66544, 54.55323, 7.6765 };

    FunArr(MYARR, MYSIZE);
    std::cout << std::endl;

    // Задание 2
    std::cout << "ZADANIE 2" << std::endl;
    const size_t MYSIZE2 = 8;
    int MYARR2[MYSIZE2] = { 1, 1, 1, 0, 0, 0, 1, 0 };

    main1(MYARR2, MYSIZE2);
    for (int k = 0; k < MYSIZE2; k++)
    {
        std::cout << MYARR2[k] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Задание 3
    std::cout << "ZADANIE 3" << std::endl;
    const size_t MYSIZE3 = 8;
    int MYARR3[MYSIZE3] = {};

    main2(MYARR3, MYSIZE3);
    for (int p = 0; p < MYSIZE3; p++)
    {
        std::cout << MYARR3[p] << " ";
    }
    std::cout << std::endl << std::endl;

    // Задание 4
    std::cout << "ZADANIE 4" << std::endl;
    int d;
    int x = {};
    const size_t MYSIZE4 = 10;
    int MYARR4[MYSIZE4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::cout << "NA SKOLKO SDVINUTb MASSIV? ";
    std::cin >> x;
    if (x > 0)
    {
        for (d = 0; d < x; d++)
        {
            sdvig(MYARR4, MYSIZE4, x);
        }

        for (int i = 0; i < MYSIZE4; i++)
        {
            std::cout << MYARR4[i] << " ";
        }
    }
    else
    {
        for (d = 0; d > x; d--)
        {
            sdvig2(MYARR4, MYSIZE4, x);
        }

        for (int i = 0; i < MYSIZE4; i++)
        {
            std::cout << MYARR4[i] << " ";
        }
    }

    std::cout << std::endl;
    return 0;
}






























/*const int n = 10;
int funarr()
{
    int mas[n]{};
    for (int i = 0; i < n; i++) 
    {
        mas[i] = { rand() % 2 };
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++) 
    {
        if (mas[i] = 1)
            mas[i] = 0;
        else
        {
            if (mas[i] = 0)
                mas[i] = 1;
        };
        std::cout << mas[i] << " ";
    }
    return 0;
}*/

/*int main()
{
    const int size = 5;
    int mass[size] = { 1, 1, 0, 0, 1 };
    
    for (int i = 0; i < size; i++)
    {
        if (mass[i] = 1)
        {
            mass[i] = 0;
        
            if (mass[i] = 0)
            {
                mass[i] = 1;
            };
        };
        std::cout << mass[i] << " ";
    };
      
    
    return 0;
}*/

/*int main()
{
    int mass[] = { 1, 1, 1, 0, 0 };

    for (int v : mass) std::cout << v << ' ';
    std::cout << std::endl;

    std::replace(std::begin(mass), std::end(mass), 1, 0);
   

    for (int v : mass) std::cout << v << ' ';
    std::cout << std::endl;
}*/

/*int main()

{
    int* ptr;
    const int size = 5;
    int mass[] = { 1, 1, 1, 0, 0 };
    for (int i = 0; i < size; i++)    
    {

    }

    return 0;
}*/


