#include <stdio.h>
#include <stdbool.h>

struct Point{
	int x;
	int y;
};

struct CheckRes{
	bool inside;
	unsigned stepNum;
	struct Point vals[50];
};

int func(int, int, int);

int m(int, int, bool);

int sign(int);
