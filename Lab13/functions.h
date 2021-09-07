#include <clocale>
#include <wchar.h>
typedef unsigned long long BitsetType;
const int maxBitsetType = 33;
struct Bitset 
{
    BitsetType set;
};

void init (struct Bitset*);
void makeIntersect (struct Bitset*, const struct Bitset);        
void addElement (struct Bitset*, int, int);               
unsigned utf8ToUnicode (unsigned char, unsigned char);
unsigned check (unsigned char);
int getCode(wchar_t);
bool isZero (struct Bitset*);
bool equality (const struct Bitset*, const struct Bitset*);


