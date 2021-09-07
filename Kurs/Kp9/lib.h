#include<stdbool.h>
struct Node {
    unsigned key;
    char* data;
    struct Node* next;
    struct Node* prev;
};
struct List {
    struct Node* head;
    bool sorted;
    int size;
};
void initList (struct List* l);
void push_back (struct List* l, unsigned key, char* data);
void print (struct List* l);
int size (const struct List* l);
void pop (struct List* l);
void free_List (struct List* l);
void func (struct List* l, unsigned k);
typedef struct Node* ListIterator;
ListIterator begin(struct List* l);
ListIterator next(ListIterator it);
ListIterator prev(ListIterator it);
ListIterator plus(ListIterator it, int x);
ListIterator end(struct  List* l);
int distance(ListIterator a, ListIterator b);
int min(int a, int b);
void swap(struct List* l, int x, int y);
void ShakerSort(struct List* l);
ListIterator find(struct List* l, int position);
char* linear_search(struct List* l, unsigned key);
char* binary_search(struct List* l, unsigned key);