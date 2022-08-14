/* 1. Написать программу, проверяющую что сумма двух (введенных с клавиатуры) чисел лежит в пределах от 10 до 20 (включительно), если да – вывести строку "true", 
в противном случае – "false";
2. Написать программу, выводящую на экран строку “true”, если две целочисленные константы, объявленные в её начале либо обе равны десяти, либо их сумма равна десяти. 
Иначе "false".
3. Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50. Например: "Your numbers: 1 3 5 7 9 11 13 …". 
Для решения используйте любой С++ цикл.
4. Со звёздочкой. Написать программу, которая заполняет диагональные элементы квадратной матрицы единицами. Размеры матрицы нужно задать константными числами 
(возьмите размер от 3 до 7, например), матрицу нужно инициализировать нулями. Вывести итоговую матрицу на экран.
5. Со звёздочкой. Написать программу, проверяющую, является ли некоторое число - простым. Простое число — это целое положительное число, 
которое делится без остатка только на единицу и себя само.
6. Со звёздочкой. Пользователь вводит с клавиатуры число (год): от 1 до 3000. Написать программу, которая определяет является ли этот год високосным. 
Каждый 4-й год является високосным, кроме каждого 100-го, при этом каждый 400-й – високосный. Вывести результаты работы программы в консоль.*/

#include <iostream>
#include <cmath>

int main()
{
    //Задание 1

    std::cout << "ZADANIE 1" << std::endl << std::endl;

    std::cout << "Enter a number A and press Enter: " << std::endl;
    int a{};
    std::cin >> a;

    std::cout << "Enter a number B and press Enter: " << std::endl;
    int b{};
    std::cin >> b;

    int c = (a + b);

    std::cout << "Youre number A: " << a << std::endl;
    std::cout << "Youre number B: " << b << std::endl;

    if (c >= 10 && c <= 20)
    {
        std::cout << "Youre result is: TRUE! " << c << std::endl << std::endl;
    }
        else 
        {        
            std::cout << "Youre result is: FALSE! " << c << std::endl << std::endl;        
        }; 
    
    // Задание 2

    std::cout << "ZADANIE 2" << std::endl << std::endl;

    std::cout << "Enter a number D and press Enter: " << std::endl;
    int d{};
    std::cin >> d;

    std::cout << "Enter a number F and press Enter: " << std::endl;
    int f{};
    std::cin >> f;

    std::cout << "Youre number D: " << d << std::endl;
    std::cout << "Youre number F: " << f << std::endl;
    
    if (d == 10 && f == 10 || (d + f) == 10) 
    {
        std::cout << "Youre result is: TRUE! " << std::endl << std::endl;
    }    
        else 
        {
            std::cout << "Youre result is: FALSE! " << std::endl << std::endl;
        };
    
    // Задание 3
 
    std::cout << "ZADANIE 3" << std::endl << std::endl;
    std::cout << "NECHETNIE CHISLA OT 1 DO 50: " << std::endl << std::endl;

    for ( int i = 1; i <= 50; i++ ) 
    {
        if (i % 2 != 0)
        {
            std::cout << i << " ";
        };        
    };
    
    std::cout << std::endl << std::endl;

    // Задание 4
    
    std::cout << "ZADANIE 4" << std::endl << std::endl;
    
    int* ptr;

    int Arr[7][7]{
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 }
    };

    ptr = &Arr[0][0];
    *ptr = 1;
    ptr = &Arr[1][1];
    *ptr = 1;
    ptr = &Arr[2][2];
    *ptr = 1;
    ptr = &Arr[3][3];
    *ptr = 1;
    ptr = &Arr[4][4];
    *ptr = 1;
    ptr = &Arr[5][5];
    *ptr = 1;
    ptr = &Arr[6][6];
    *ptr = 1;

    for (int x = 0; x <= 6; x++) 
    {
        for (int y = 0; y <= 6; y++) 
        {
            std::cout << Arr[x][y] << " ";                       
        };
        std::cout << std::endl;        
    };
    std::cout << std::endl;

    // Задание 5
    
    std::cout << "ZADANIE 5" << std::endl << std::endl;

    int j;

    std::cout << "Enter a number and press Enter: " << std::endl;

    int g{};
    std::cin >> g;
    while (g <= 2)
    {
        std::cout << "Enter a number > 2 and press Enter: " << std::endl;
        std::cin >> g;
    };

    for (j = 2; j <= sqrt(g); j++)
    {
        if (g % j == 0)
        {
            std::cout << "Youre result is: CHISLO NE PROSTOE!" << " TAK KAK DELITSA NA " << j << std::endl << std::endl;
            break;
        };
    };

    if (g % j != 0)
    {
        std::cout << "Youre result is: CHISLO PROSTOE!" << std::endl << std::endl;
    };
    
    //Задание 6
    
    std::cout << "ZADANIE 6" << std::endl << std::endl;
    std::cout << "Enter a Year for 1 - 3000 and press Enter: " << std::endl;
    int w{};
    std::cin >> w;

    while (w <= 0 || w > 3000)
    {
        std::cout << "Enter a Year for 1 - 3000 and press Enter: " << std::endl;
        std::cin >> w;
    };

    if (w % 4 == 0 && w % 100 != 0 || w % 400 == 0)
    {
        std::cout << "Youre result is: GOD VISOKOSNIY" << std::endl << std::endl;
    }    
        else 
        {
            std::cout << "Youre result is: GOD NE VISOKOSNIY" << std::endl << std::endl;        
        };
    return 0;
}