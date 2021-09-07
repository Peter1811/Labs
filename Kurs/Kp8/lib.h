#include <stdbool.h>
struct Node{
    int value;
    struct Node* next;
    struct Node* prev;
};
struct List{
    int size;
    struct Node* head;
};
typedef struct{
    struct Node* node;
} It;
It begin(struct List* list);
It end(struct List* list);
It next(It* i);
It prev(It* i);
bool compare(It* left, It* right);
It AddElement(struct List* list,It* i,int number);
It delete(struct List* list,It* i);
bool isempty(struct List* list);
void initlist(struct List* list);
void PrintList(struct List* l);
It distance(struct List* list, int number);
void function(struct List* list,int fsize, int num);
void DelList(struct List* list);
It last(struct List* list);