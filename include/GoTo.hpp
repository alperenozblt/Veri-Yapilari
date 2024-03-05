#ifndef GOTO_HPP
#define GOTO_HPP

#include <windows.h>

static class GoTo {
public:

    static void gotoxy(int x, int y) {
        COORD k;
        k.X = x;
        k.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
    }


} GoTo;


#endif 