#include <stdio.h>

using namespace std;

int main(){
	int mas[4][4];
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			scanf("%d", &mas[i][j]);
			//printf("%d", mas[i][j]);
		}
		//printf("\n");
	};

	for(int i=0; i<4; i++){
		printf("%d ", mas[i][3]);
	};
	//printf("\n");
	//
	for(int j=2; j>=0; j--){
		printf("%d ", mas[3][j]);
	};

	for(int i=2; i>=0; i--){
		printf("%d ", mas[i][0]);
	};
        for(int j=1; j<3; j++){
		printf("%d ", mas[0][j]);
	};
	for(int i=1; i<3; i++){
		printf("%d ", mas[i][2]);
	};
	for(int i=2; i>0; i--){
		printf("%d ", mas[i][1]);
	};	

	return 0;
}
