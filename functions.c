#include "functions.h"

int func(int x, int y, int R){
	return x*x + y*y - R*R;
};

int m(int x, int y, bool m_t){
	if(m_t){
		if(x > y) return x;
		else return y;
	}

	else{
		if(x < y) return x;
		else return y;
	}
};

int sign(int x){
	if(x >= 0) return 1;
	else return -1;
};
