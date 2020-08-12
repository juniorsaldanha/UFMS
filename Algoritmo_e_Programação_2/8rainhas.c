#include <stdio.h>
#include <stdbool.h>
#include <string.h>
void funcao(int n, int resp[], bool row[], bool rightDiag[], bool leftDiag[]){
	int i, j;
	if(n == 8){
		for (j = 0; j < 8; ++j){
			printf("%d", resp[j]);
		}
		printf("\n");
	}
	else{
		for(i = 0; i < 8; ++i){
			if(row[i] && rightDiag[n - i + 8] && leftDiag[n + i]){
				row[i] = rightDiag[n - i + 8] = leftDiag[n + i] = false;
				resp[n] = i + 1;
				funcao(n+1, resp, row, rightDiag, leftDiag);
				row[i] = rightDiag[n - i + 8] = leftDiag[n + i] = true;
			}
		}
	}
}
int main(){
	int resp[10];
	bool row[10];
	bool rightDiag[20];
	bool leftDiag[20];


	memset(row, true, sizeof(row));
	memset(rightDiag, true, sizeof(rightDiag));
	memset(leftDiag, true, sizeof(leftDiag));

	funcao(0, resp, row, rightDiag, leftDiag);
	return 0;
}