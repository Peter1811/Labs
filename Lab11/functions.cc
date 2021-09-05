#include "functions.h"
#include <cctype>

State WordCount(const State currentState, const int currentSymbol){
        State newState;
        switch(currentState) {

                case Start:
                        {
                                if(currentSymbol == '/') {
                                        newState = Slash;
                                } else {
					newState = Start;
				}
                                break;
                        }
		case Slash:
			{
				if(currentSymbol == '*') {
					newState = Space;
				} else {
					newState = Start;
				}
				break;
			}
		case Star:
			{
				if(currentSymbol == '/') {
					newState = Start;
				} else if((currentSymbol == ' ') || (currentSymbol == '\n') || (currentSymbol == '\t')) {
					newState = Word;
				} else {
					newState = Letter;
				}	
				break;
			}
                case Space:
                        {
                                if((currentSymbol == ' ') || (currentSymbol == '\n') || (currentSymbol == '\t')) {
                                        newState = Space;
				} else if(currentSymbol == '*') {
					newState = Star;
                                } else if(isalpha(currentSymbol)) {
                                        newState = Letter;
                                }
                                break;
                        }
                case Letter:
                        {
                                if((currentSymbol == ' ') || (currentSymbol == '\n') || (currentSymbol == '\t')) {
                                        newState = Word;
				} else if(currentSymbol == '*') {
					newState = Star_Word;
                                } else {	
                                        newState = Letter;
                                }
                                break;
			}
                default:
                        {
                                newState = Error;
                                break;
                        }

	        }
        return newState;
}

