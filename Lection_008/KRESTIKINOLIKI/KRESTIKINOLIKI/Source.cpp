#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>
#include <windows.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include "conio.h"
#include <cwchar>
#include <mmsystem.h>
#include <audiere.h>
#include "bass.h"
#include <cstdlib>
#pragma comment (lib, "Winmm.lib")
#pragma comment (lib, "Audiere.lib")
#pragma comment(lib, "bass.lib")

using namespace std;
using namespace audiere;

enum TCell : char
{
    Cross = 'X',
    Zero = '0',
    Empty = '_'
};

struct TCoord
{
    size_t y = { 0U };
    size_t x = { 0U };
};

enum TProgress
{
    InProgress,
    WonHuman,
    WonAI,
    Draw
};

#pragma pack(push, 1)
struct TGame
{
    TCell** ppField{ nullptr };
    const size_t Size{ 3U };
    TProgress Progress{ InProgress };
    TCell human, ai;
    size_t turn{ 0U };
};
#pragma pack(pop)

//********************************************************************************************
//********************************************************************************************

int32_t getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

void InitGame(TGame& g)
{
    g.ppField = new TCell * [g.Size];
    for (size_t i = 0U; i < g.Size; i++)
    {
        g.ppField[i] = new TCell[g.Size];
    }

    for (size_t y = 0; y < g.Size; y++)
    {
        for (size_t x = 0; x < g.Size; x++)
        {
            g.ppField[y][x] = Empty;
        }
    }

    if (getRandomNum(0, 1000) > 500)
    {
        g.human = Cross;
        g.ai = Zero;
        g.turn = 0;
    }
    else
    {
        g.human = Zero;
        g.ai = Cross;
        g.turn = 1;
    }
}
void DeInitGame(TGame& g)
{
    for (size_t i = 0U; i < g.Size; i++)
    {
        delete[] g.ppField[i];
    }

    delete[] g.ppField;
    g.ppField = nullptr;
}

void PrintGame(const TGame& g)
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 40;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    cout << "                                  " << "###############" << endl;
    cout << "                                  " << "###############" << endl;
    cout << "                                  " << "##    ###    ##" << endl;
    cout << "                                  " << "     ";
    for (size_t x = 0; x < g.Size; x++)
    {
        cout << x + 1 << "  ";
    }
    cout << endl;

    for (size_t y = 0; y < g.Size; y++)
    {
        cout << "                                    ";
        cout << y + 1;
        HANDLE pole1 = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(pole1, 6);
        cout << "_|";
        SetConsoleTextAttribute(pole1, 7);

        for (size_t x = 0; x < g.Size; x++)
        {
            HANDLE pole2 = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(pole2, 6);

            cout << g.ppField[y][x] << "_|";
            SetConsoleTextAttribute(pole2, 7);
        }
        cout << endl << endl;
    }
    cout << "                                  " << "##    ###    ##" << endl;
    cout << "                                  " << "###############" << endl;
    cout << "                                  " << "###############" << endl;

    HANDLE humansymbol = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(humansymbol, 10);
    cout << "                                  " << "HUMAN: " << g.human << endl;
    SetConsoleTextAttribute(humansymbol, 7);

    HANDLE aisymbol = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(aisymbol, 4);
    cout << "                                  " << "COMPUTER: " << g.ai << endl << endl;
    SetConsoleTextAttribute(aisymbol, 7);
}

void Congrats(const TGame& g)
{
    if (g.Progress == WonHuman)
    {
        PlaySound(TEXT("pobeda.wav"), NULL, SND_FILENAME | SND_ASYNC);

        HANDLE humanwon = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(humanwon, 10);
        cout << "                                  " << "HUMAN WON! ^_^" << endl << endl;
        SetConsoleTextAttribute(humanwon, 7);
    }
    else if (g.Progress == WonAI)
    {
        PlaySound(TEXT("pobedacomputer.wav"), NULL, SND_FILENAME | SND_ASYNC);

        HANDLE aiwon = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(aiwon, 4);
        cout << "                                  " << "COMPUTER WON! >_<" << endl << endl;
        SetConsoleTextAttribute(aiwon, 7);
    }
    else if (g.Progress == Draw)
    {
        PlaySound(TEXT("draw.wav"), NULL, SND_FILENAME | SND_ASYNC);

        HANDLE draw = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(draw, 9);
        cout << "                                  " << "DRAW! =_=" << endl << endl;
        SetConsoleTextAttribute(draw, 7);
    }
}
TProgress getWon(const TGame& g)
{
    for (size_t y = 0; y < g.Size; y++)
    {
        if (g.ppField[y][0] == g.ppField[y][1] && g.ppField[y][0] == g.ppField[y][2])
        {
            if (g.ppField[y][0] == g.human)
            {
                return WonHuman;
            }
            if (g.ppField[y][0] == g.ai)
            {
                return WonAI;
            }
        }
    }
    for (size_t x = 0; x < g.Size; x++)
    {
        if (g.ppField[0][x] == g.ppField[1][x] && g.ppField[0][x] == g.ppField[2][x])
        {
            if (g.ppField[0][x] == g.human)
            {
                return WonHuman;
            }
            if (g.ppField[0][x] == g.ai)
            {
                return WonAI;
            }
        }
    }
    if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2])
    {
        if (g.ppField[1][1] == g.human)
        {
            return WonHuman;
        }
        if (g.ppField[1][1] == g.ai)
        {
            return WonAI;
        }
    }
    if (g.ppField[0][2] == g.ppField[1][1] && g.ppField[2][0] == g.ppField[1][1])
    {
        if (g.ppField[1][1] == g.human)
        {
            return WonHuman;
        }
        if (g.ppField[1][1] == g.ai)
        {
            return WonAI;
        }
    }
    bool draw{ true };
    for (size_t y = 0; y < g.Size; y++)
    {
        for (size_t x = 0; x < g.Size; x++)
        {
            if (g.ppField[y][x] == Empty)
            {
                draw = false;
                break;
            }
        }
        if (!draw)
            break;
    }
    if (draw)
        return Draw;
    return InProgress;
}



TCoord getAICoord(TGame& g)
{
    for (size_t y = 0; y < g.Size; y++)
    {
        for (size_t x = 0; x < g.Size; x++)
        {
            if (g.ppField[y][x] == Empty)
            {
                g.ppField[y][x] = g.human;
                if (getWon(g) == WonHuman)
                {
                    g.ppField[y][x] = Empty;
                    return { y, x };
                }
                g.ppField[y][x] = Empty;
            }
        }
    }

    for (size_t y = 0; y < g.Size; y++)
    {
        for (size_t x = 0; x < g.Size; x++)
        {
            if (g.ppField[y][x] == Empty)
            {
                g.ppField[y][x] = g.ai;
                if (getWon(g) == WonAI)
                {
                    g.ppField[y][x] = Empty;
                    return { y, x };
                }
                g.ppField[y][x] = Empty;
            }
        }
    }

    if (g.ppField[1][1] == Empty)
    {
        return{ 1, 1 };
    }

    TCoord buf[4];
    size_t num{ 0U };
    if (g.ppField[0][0] == Empty)
    {
        buf[num] = { 0, 0 };
        num++;
    }
    if (g.ppField[2][0] == Empty)
    {
        buf[num] = { 2, 0 };
        num++;
    }
    if (g.ppField[0][2] == Empty)
    {
        buf[num] = { 0, 2 };
        num++;
    }
    if (g.ppField[2][2] == Empty)
    {
        buf[num] = { 2, 2 };
        num++;
    }
    if (num > 0)
    {
        const size_t index = getRandomNum(0, 1000) % num;
        return buf[index];
    }

    if (g.ppField[1][0] == Empty)
    {
        buf[num] = { 1, 0 };
        num++;
    }
    if (g.ppField[0][1] == Empty)
    {
        buf[num] = { 0, 1 };
        num++;
    }
    if (g.ppField[1][2] == Empty)
    {
        buf[num] = { 1, 2 };
        num++;
    }
    if (g.ppField[2][1] == Empty)
    {
        buf[num] = { 2, 1 };
        num++;
    }
    if (num > 0)
    {
        const size_t index = getRandomNum(0, 1000) % num;
        return buf[index];
    }
    return { 0, 0 };
}