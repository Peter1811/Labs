#include <iostream>

struct Point{
    int x;
    int y;
};

struct CheckRes{
    bool inside;
    unsigned step;
    struct Point mas[50];
};

int func(int, int, int);

int maximum(int, int);

int sign(int);