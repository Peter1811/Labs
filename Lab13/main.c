#include <stdio.h>
#include "functions9.h"
int main()
{
	//setlocale(LC_ALL, "ru_RU.UTF8");
	setlocale(LC_ALL, "");
        struct Bitset CC;
        init (&CC);
	struct Bitset CP;
	init (&CP);
        struct Bitset UC;
        init (&UC);
        struct Bitset UP;
        init (&UP); 
	struct Bitset aux;
	init (&aux);
        int symb;
        unsigned counter = 0;
        unsigned buff[2];
	wchar_t firstWord[1002];
	wchar_t secondWord[1002];
	int current_am = 0;
	int previous_am = 0;
	int am_printed = 0;
	int firstCode;
	unsigned code;
	bool tooLong = 0;
        while ((symb = getchar()) != EOF) 
	{
                buff[counter] = symb;
                counter++;
                if (counter == 1)
                {
                        if ((check(buff[0])) == 0)
                        {
                                counter = 0;
				tooLong = 0;
                                if (((isZero(&CP)) == 1) && (isZero(&UP) == 1))
				{
			                CP = CC;
			                UP = UC;
			                for (int i = 0; i < current_am; i++)
				        {
						firstWord[i] = secondWord[i];
				        }		
                                        previous_am = current_am;
					current_am = 0;
                                        makeIntersect(&CC, aux);
                                        makeIntersect(&UC, aux);
                                        continue;					
				}
				else if ((isZero(&CC) != 1) || (isZero(&UC) != 1))
				{
				        if ((equality(&CC, &CP) == 1) && (equality(&UC, &UP) == 1))
					{
                                                 am_printed++;
						 if (am_printed == 1)
						 {
					wprintf(L"Данные пары соседних слов состоят из одинаковых символов:\n");
						 }
                                                 for (int i = 0; i < previous_am; i++)
						 {
							 wprintf(L"%lc", firstWord[i]);
						 }
						 wprintf(L" ");
						 for (int i = 0; i < current_am; i++)
						 {
							 wprintf(L"%lc", secondWord[i]);
						 }
						 wprintf(L"\n");
				        }
				        for (int i = 0; i < current_am; i++)
                                                 {
                                                         firstWord[i] = secondWord[i];
                                                 }
                                                 previous_am = current_am;
						 current_am = 0;
                                                 CP = CC;
						 UP = UC;
                                                 makeIntersect(&CC, aux);
                                                 makeIntersect(&UC, aux);	
				continue;
				}
                       }
                } 
                if ((counter == 2) && (tooLong == 0))
		{
                        code = utf8ToUnicode(buff[0], buff[1]);
			if (code > getCode(L'Е'))
                        {
                                code++;
                        }
                        if (code == getCode(L'Ё'))
                        {
                                code = getCode(L'Ж');
                        }
                        if (code > getCode(L'ж'))
                        { 
                                code++;
                        }
                        if (code == getCode(L'ё') + 2)
                        {
                                code = getCode(L'з');
                        }
                        counter = 0;
	                if ((code >= getCode(L'А')) && (code < getCode(L'б')))
		        {
	                        firstCode = getCode (L'А');
                                addElement(&CC, code, firstCode);
		        }
	                else if (code > getCode(L'а'))
	                {
		                firstCode = getCode (L'а') + 1;
                                addElement(&UC, code, firstCode);
	                }
                        if (code == getCode(L'Ж'))
                        {
                                code = getCode(L'Ё');
                        }
                        if (code > getCode(L'Ж'))
                        {
                                code--;
                        }
                        if (code == getCode(L'ж'))
                        {
                                code = getCode(L'ё');
                        }
                        if ((code > getCode(L'е')) && (code < getCode(L'ё')))
                        {
                                code--;
                        }
			if (current_am > 1000)
			{
				tooLong = 1;
				current_am = 0;
				previous_am = 0;
				makeIntersect (&CC, aux);
				makeIntersect (&UC, aux);
				CP = CC;
				UP = UC;
				continue;
			}
			secondWord[current_am] = wchar_t(code);
			current_am++;
                        continue;
                }
		else if ((counter == 2) && (tooLong == 1))
		{
			counter = 0;
		}
       }	
       if (am_printed == 0)
       {
		wprintf(L"Не нашлось подходящих соседних слов\n");
       }
       return 0;
}
