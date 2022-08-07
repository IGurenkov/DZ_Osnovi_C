#include <iostream>
/*
1. Создать и инициализировать переменные пройденных типов данных (short int, int, long long, char, bool, float, double).
2. Создать перечисление (enum) с возможными вариантами символов для игры в крестики-нолики.
3. Создать массив, способный содержать значения такого перечисления и инициализировать его.
4. * Создать структуру (struct) данных «Поле для игры в крестики-нолики» и снабдить его всеми необходимыми свойствами (подумайте что может 
понадобиться).
5. ** Создать структуру (struct MyVariant) объединяющую: union MyData (int, float, char) и 3-и битовых поля (флага) 
указывающими какого типа значение в данный момент содержится в 
объединении (isInt, isFloat, isChar). Продемонстрировать пример использования в коде этой структуры.*/
int main()
{
    // Первое задание
    short int a = 24000; // short int a { 24000 };
    int b = -1456344235; // int b { -1456344235 };
    long long c = 8223372036854775807; // long long c { 8223372036854775807 };
    char d = 'B';
    bool e = false; // or bool e = true; 
    float f = 3.2789678f; // float f { 3.2789678f }; Выводится 3.27897
    double g = 1.9877564; // double g { 1.9877564 }; Выводится 1.98776
    
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << f << std::endl;
    std::cout << g << std::endl;

    // Второе задание
    enum VariantVvoda { x, o, pusto = '*' };

    // Третье задание
    char arr[3][3][3]
    {

        {{ x, o, pusto }, { x, o, pusto }, { x, o, pusto }},
        {{ x, o, pusto }, { x, o, pusto }, { x, o, pusto }},
        {{ x, o, pusto }, { x, o, pusto }, { x, o, pusto }}

    };
    
    // Четвертое задание
    struct Pole
    {
        char arr[3][3][3];
        bool igranachalas = true;
        bool igranenachalas = false;
        char player1 = x;
        char player2 = o;

    };

    return 0;
}


