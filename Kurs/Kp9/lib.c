#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void initList (struct List* l) {
    l->head = NULL;
    l->sorted = false;
    l->size = 0;
}
void push_back (struct List* l, unsigned key, char* data) {
    if (l->head == NULL) {
        l->head = (struct Node*) malloc(sizeof (struct Node));
        l->head->key = key;
        l->head->data = data;
        l->head->next = l->head->prev =l->head;
    } else {
        ListIterator it = begin(l);
        while(next(it) != begin(l)) {
            it = next(it);
        }
        it->next = (struct Node*)malloc(sizeof(struct Node));
        it->next->prev = prev(it->next);
        it->next->key = key;
        it->next->data = data;
        it->next->next = begin(l);
    }
    ++(l->size);
}
void pop(struct List* l) {
    if (l->size == 0) {
        return;
    }
    if (l->size == 1) {
        free(l->head->data);
        free(l->head);
        initList(l);
        return;
    }
    ListIterator it = begin(l);
    it = plus(it, l->size - 2);
    free(it->next->data);
    free(it->next);
    l->size--;
}
void print(struct List* l) {
    printf("\n");
    if (l->size == 0) {
        printf("List is empty\n");
        return;
    }
    ListIterator it = begin(l);
    for (int i = 0; i < l->size; i++) {
        printf("%d::%s\n", it->key, it->data);
        it = next(it);

    }

    printf("\n");

}

void free_List (struct List* l) {

    int s = l->size;

    for (int i = 0; i < s; i++) {

        pop(l);

    }

}

int size (const struct List* l) {

    return l->size;

}

void swap (struct List* l, int x, int y) {

    ListIterator it_x = begin(l);
    it_x = plus(it_x, x);
    ListIterator it_y = begin(l);
    it_y = plus(it_y, y);

    unsigned key;
    char* data;

    key = it_x->key;
    data = it_x->data;

    it_x->key = it_y->key;
    it_x->data = it_y->data;

    it_y->key = key;
    it_y->data = data;

}

ListIterator begin(struct List* l) {
    if (!l || !l->head) {
        return NULL;
    }
    return l->head;
}
ListIterator prev(ListIterator it){
    return it->prev;
}
ListIterator next(ListIterator it) {
    return it->next;
}
ListIterator plus(ListIterator it, int x) {
    for (int i = 0; i < x; i++) {
        it = it->next;
    }
    return it;
}
int min(int a, int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}
int distance(ListIterator a, ListIterator b) { // pos_a <= pos_b

    int dis = 0;
    ListIterator cur = a;
    while (cur != b) {

        dis++;
        cur = next(cur);

    }

    return dis;

}

ListIterator end(struct List* l) {

    return NULL;

}
ListIterator find(struct List* l, int position){
    ListIterator a = begin(l);
    for (int i = 0; i<position; i++){
        a = next(a);
    }
    return a;
}

void ShakerSort(struct List* l)
{
  int left = 0;
  int right = l->size-1; 
  int flag = 1;

  while ((left < right) && flag > 0)
  {
    flag = 0;
    for (int i = left; i<right; i++) 
    {
      if (find(l, i)->key>find(l, i+1)->key) 
      {             
        swap(l, i, i+1);
        flag = 1;     
      }
    }
    right--;
    for (int i = right; i>left; i--) 
    {
      if (find(l, i-1)->key>find(l, i)->key) 
      {            
        swap(l, i-1, i);
        flag = 1;
      }
    }
    left++;
  }
}
char* linear_search(struct List* l, unsigned key){
    ListIterator a = begin(l);
    int count = 0;
    while (a->key!=key && count<l->size){
        a = next(a);
        count++;
    }
    printf("%s\n", a->data);
}
char* binary_search(struct List* l, unsigned key){
    ListIterator a = begin(l);
    ListIterator b = begin(l);
    while(next(b)!=begin(l)) next(b);
}
