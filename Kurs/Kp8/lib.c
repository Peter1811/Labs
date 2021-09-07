#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
It begin(struct List* list){
    It ans = {list->head->next};
    return ans;
}
It end(struct List* list){
    It ans = {NULL};
    return ans;
}
It next(It* i){
    i->node = i->node->next;
    It ans = {i->node};
    return ans;
}
It prev(It* i){
    i->node = i->node->prev;
    It ans = {i->node};
    return ans;
}
It last(struct List* list){
    It ans = {list->head};
    return ans;
}
bool compare(It* comp1, It* comp2){
    return comp1->node == comp2->node;
}
It AddElement(struct List* list,It* i,int number){
    It sub = {(struct Node*)malloc(sizeof(struct Node*))};
    sub.node->value = number;
    sub.node->next = i->node;
    sub.node->prev=i->node->prev;
    sub.node->prev->next=sub.node;
    i->node->prev=sub.node;
    list->size++;
    return sub;
}
bool isempty(struct List* list){
    It a = begin(list);
    It b =last(list);
    return compare(&a,&b);
}
void initlist(struct List* list){
    list->head =(struct Node*) malloc(sizeof(struct Node*));
    list->size = 0;
    list->head->next = list->head->prev = list->head;
    list->head->value = 0;
}
It distance(struct List* list, int number){
    It a = begin(list);
    It b = last(list);
    if(compare(&a, &b)){
        return a;
    }
    while(a.node->value != number){
        next(&a);
        if(compare(&a, &b)) return a;
    }
    return a;
}
It delete(struct List* list,It* i){
    It sub = last(list);
    if (compare(&sub,i)) return sub;
    sub.node = i->node->next;
    sub.node->prev = i->node->prev;
    i->node->next->prev = sub.node->prev;
    i->node->prev->next = sub.node;
    list->size--;
    free(i->node);
}
void DelList(struct List* list){
    It i;
    while(list->size !=0){ 
        i = begin(list);
        delete(list, &i);
    };
    free(list->head);
    list->head = NULL;
    list->size = 0;
}
void function(struct List* list, int k, int num){
    if (k>list->size){
        for (int i = list->size; i<k; i++){
    It a = begin(list);
    It b = last(list);
    if (!compare(&a, &b)){
        for (int j = 0; j<list->size; j++){
            next(&a);
            if(compare(&a, &b)) break;
        }
     }
     AddElement(list, &a, num);
    }
    }

}
void PrintList(struct List* l){
    It a = begin(l);
    It b = last(l);
    if(compare(&a, &b)) printf("Empty");
    while(!compare(&a, &b)){
        printf("%d ", a.node->value);
        next(&a);
    }
    printf("\n");
}
