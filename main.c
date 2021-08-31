#include "functions.h"
#include <stdlib.h>
#include <stdio.h>

struct CheckRes check(struct Point* p, int l0){
	CheckRes result = {.inside = false,
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
		l0 = sign(i-10)*abs(int(p->x-p->y+l0-i));

	}
	return result;
};

int main(){
	struct Point p;
	p.x = 18;
	p.y = -9;
	int l0 = 5;
	struct CheckRes k = check(&p, l0);
	if(k.inside == true){
		printf("%d step.\n", k.stepNum);
		printf("%d %d %d\n", p.x, p.y, l0);
	}
	else printf("Ne popalo");

	return 0;
}



