#include "functions.h"

struct CheckRes check(struct Point* p, int l0){
	struct CheckRes result = {.inside = false,
			   .stepNum = 0};
	for(unsigned i = 0; i < 50; ++i){
		bool pointinside = ((func(p->x, p->y, 5) > 0 && func(p->x, p->y, 10) < 0));
		result.vals[i] = *p;
		if(pointinside){
			result.inside = true;
			result.stepNum = i;
			break;
		}
		p->x = p->x*(m(p->y, l0, true))%30 + p->y*m(p->x, l0, false)%20 + i;
		p->y = m(p->x, m(p->y, m(l0, m(p->x - l0, p->y - l0, true), false), true), false);
		l0 = sign(i-10)*abs((signed int)p->x-p->y+l0-i);

	}
	return result;
};

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
