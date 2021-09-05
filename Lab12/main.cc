#include <stdio.h>

int main(){
	char mas[2];
	long long a;
	int kol1=0, kol2=0, kol=0;
	scanf("%lld", &a);
	mas[1] = a % 10;
	mas[0] = (a/10)%10;
	while(a>0){
		kol += 1;
		//printf("%d %d\n", mas[0], mas[1]);
		if(mas[0]==mas[1]) kol1 += 1;
		else kol2 += 1;
		mas[1] = (a/10)%10;
		mas[0] = (a/100)%10;
	        a = a/10;	

	}
	//printf("%d %d\n", kol1, kol2);
	if(kol1==kol-1) printf("All numbers are same\n");
	else if(kol1<kol && kol2<kol) printf("Not all numbers are different\n");
	else if(kol2==kol) printf("All numbers are different\n");
}

