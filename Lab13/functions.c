#include <stdio.h>
#include "functions9.h"

void init (struct Bitset* bs)
{
    bs->set = 0; 
}

void makeIntersect (struct Bitset* bs, const struct Bitset r)
{
    bs->set = bs->set & r.set;
}

void addElement (struct Bitset* bs, int element, int code)
{
     bs->set = bs->set | (1ull << (element - code)); 
}

bool isZero (struct Bitset* bs)
{
        bool yes = 1;
        for (int i = maxBitsetType - 1; i >= 0; --i)
        {
        bool isCurrentValZero = (bs->set & (1ull << i)) == 0;
        if (isCurrentValZero) {
        continue;
        }
        else
        {
                yes = 0;
                break;
        }
    }
    return yes;
}

bool equality (const struct Bitset* bs, const struct Bitset* r)
{
        bool yes = 1;
        for (int i = maxBitsetType - 1; i >= 0; i--)
        {
                bool digit10 = (bs->set & (1ull << i)) == 0;
                bool digit20 = (r->set & (1ull << i)) == 0;
                if (digit10)
                {
                        if (digit20)
                        {
                                continue;
                        }
                        else
                        {
                                yes = 0;
                                break;
                        }
                }
                else
                {
                        if (digit20)
                        {
                                yes = 0;
                                break;
                        }
                        else
                        {
                                continue;
                        }
                }
        }
        return yes;
}

unsigned utf8ToUnicode (unsigned char firstByte, unsigned char secondByte)
{
    unsigned firstDigit = firstByte & 31;
    unsigned secondDigit = secondByte & 63;
    return (firstDigit << 6) | secondDigit;
}

unsigned check (unsigned char Byte)
{
        unsigned digit = Byte & 128;
        return digit;
}

int getCode (wchar_t Letter)
{
	int code = int(Letter);
        return code;
}
