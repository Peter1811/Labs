#include <stdio.h>
#include <cctype>
#include "functions.h"

int main() {
	
	State currentState = Start;
	int WordsInComments = 0;
	int symbol;

	do {
		symbol = getchar();
		currentState = WordCount(currentState, symbol);
		if (currentState == Word){
			++WordsInComments;
			currentState = Space;
		} else if(currentState == Star_Word){
			++WordsInComments;
			currentState = Star;
		}
	} while (symbol != EOF);
	
	printf("%u\n", WordsInComments);

}
