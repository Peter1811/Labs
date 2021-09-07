#include <stdio.h>
using namespace std;

int main(){
	int mas[8][8];
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &mas[i][j]);
		}
	};
	
	int mas1[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			mas1[i][j] = 0;
			for(int k = 0; k < n; k++){
            			mas1[i][j] += mas[i][k] * mas[k][j];
    
				
									
			}
		}
			//mas1[i][j] = sum;
	};
		
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", mas1[i][j]);
		}
		printf("\n");
	};




	return 0;

}
