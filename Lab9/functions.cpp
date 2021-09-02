//
// Created by shand on 02.09.2021.
//
#include "functions.h"

struct CheckRes check(struct Point *p, int l0){
    CheckRes result = {.inside = false, .step = 0};
//    bool point_inside = (func(p->x, p->y, 5) > 0 && func(p->x, p->y, 10) < 0);
    for (int i = 0; i < 50; ++i){
        bool point_inside = (func(p->x, p->y, 5) > 0 && func(p->x, p->y, 10) < 0);
        result.mas[i] = *p;
        if (point_inside){
            result.inside = true;
            result.step = i;
            break;
        }
        p->x = maximum(p->y - i, l0 - i) % 30 + maximum(p->x + l0, p->y + i) % 20;
        p->y = (abs(p->x - l0) * sign(p->y + i) + abs(p->x - i) * (p->y + i)) % 20;
        l0 = (p->x + i) * (p->y - i) * (l0 + i) % 25;
    }
    return result;
}

int func(int x, int y, int R){
    return x*x + y*y - R*R;
}

int maximum(int a, int b){
    if (a > b) return a;
    else return b;
}

int sign(int a){
    if (a >= 0) return 1;
    else return -1;
}

