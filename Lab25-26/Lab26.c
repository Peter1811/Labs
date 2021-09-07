#include "Lab26.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
    void initStack(Stack* s){
	s->capacity = 2;
        s->nodes = (Token*)malloc(sizeof(Token)*s->capacity);
        s->size = 0;
    }
    void push(Stack* s, Token element){
        if (s->size == s->capacity){
            s->capacity = s->capacity * 2;
            s->nodes = (Token*)realloc(s->nodes, sizeof (Token)*s->capacity);
        };
        if (s->size == 0){
            s->nodes[s->size] = element;
            s->size++;
        }
        else{
            for (int i = s->size; i > 0; i--){
                s->nodes[i] = s->nodes[i-1];
            };
                s->nodes[0] = element;
                s->size++; 
        }
    }
    Token pop(Stack* s){
        if (s->size == 0) printf("Stack is empty\n");
        else {
            Token element;
            element = s->nodes[0];
            for (int i = 0; i < s->size; ++i){
                s->nodes[i] = s->nodes[i+1];
            };
            --s->size;
           // printf("returned element: "); printf("%d", element.value); printf("\n");
            return element;
        }
    }
    bool isEmpty(Stack* s){
        if (s->size == 0) return true;
        else return false;
    }
    void PrintStack(Stack* s){
        if (s->size == 0) printf("Stack is empty\n");
        else {
            for (int i = 0; i<s->size; i++){
                printf("%d ", s->nodes[i].value);
            };
            printf("\n");
        }
    }
    void function(Stack* s, Stack* n){
	   int k;
      	int t = s->size;
	//printf("%d\n", t);
	    for(int i=0; i<t; i++){
		while(s->size>1){
			//printf("%d\n", t);
		    
		Token a = pop(s);
	    	Token b = pop(s);
		if(a.value>b.value){ push(n, b);
			push(s, a);}
		else{
		       	push(n, a);	
			push(s, b);
		}
		//PrintStack(s);
		//printf("\n");
		//PrintStack(n);
		
	    }
		
		k = n->size;
		for(int j=0; j<k; j++){
			Token c = pop(n);
			push(s, c);
		}
	     
	   
        
    }
    }
    void clearStack(Stack* n){
	free(n->nodes);

    }
    void sort(Stack *s){
        
        Stack n;
        initStack(&n);
        function(s, &n);

	clearStack(&n);


    }
