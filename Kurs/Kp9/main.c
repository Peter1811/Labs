#include<stdio.h>
#include<stdlib.h>
#include "lib.h"

int main() {
    struct List l;
    initList(&l);
    char symbol;
    while ((symbol = getchar()) != EOF) {
        switch(symbol) {
            case '+': { 
                getchar();
                unsigned key;
                char* data = (char*)malloc(10);
                scanf("%d", &key);
                scanf("%s", data);
                push_back(&l,key,data);
                l.sorted = false;
                break;
            }
            case 'p': { 
                print(&l);
                break;
            }
            case '-': {
                pop(&l);
                break;
            }
            case 's': {
                ShakerSort(&l);
                l.sorted = true;
                break;
            }
            case 'f': {
                getchar();
                unsigned key;
                scanf("%d", &key);
                if (l.sorted == false) linear_search(&l, key);
                else binary_search(&l, key);
                break;
            }

            }
        }
    }
    free_List(&l);
}
