#ifndef LAB26_H
#define LAB26_H
#include <stdbool.h>
#include <stdio.h>

typedef struct{
    int value;
} Token;
typedef struct{
    Token* nodes;
    unsigned capacity;
    unsigned size;
} Stack;
void initStack(Stack*);
void push(Stack*, Token);
Token pop(Stack*);
void sort(Stack*);
void clearStack(Stack*);
void function(Stack*, Stack*);
void PrintStack(Stack*);
bool isEmpty(Stack*);
#endif
