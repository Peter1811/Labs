#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main() {
    struct List list;
    initlist(&list);
    char opchoose;
    while ((opchoose = getchar()) != EOF) {
        switch(opchoose){
            case '+':{
                int position,insert;
                scanf("%d %d",&position,&insert);
                It a = begin(&list);
                It b = last(&list);
                for (int i=1;i<position;i++){
                    if (compare(&a,&b)) break;
                    next(&a);
                }
                AddElement(&list,&a,insert);
                break;
            }
            case 'p':{
                PrintList(&list);
                break;
            }
            case '-':{
                int number;
                scanf("%d", &number);
                It c = distance(&list, number);
                delete(&list, &c);
                break;
            }
            case 'f':{
                int fsize,num;
                getchar();
                scanf("%d %d",&fsize, &num);
                function(&list, fsize, num);
                PrintList(&list);
                break;
            }
            
        }
    }
    DelList(&list);
} 