#include <stdio.h>
#define MAX 100

int linha(int A[MAX][MAX], int n, int i){
	int presente[n];
	int j;

	for(j = 0; j < n; ++j){
		if(A[i][j] <= n){
			int elemento = (A[i][j] - 1);
			presente[elemento] = 1;
		}
		else{
			return 0;
		}
	}
	for(j = 0; j < n; ++j){
		if(presente[j] == 0){
			return 0;
		}
	}

	return 1;
}

int coluna(int A[MAX][MAX], int n, int i){
	int presente[n];
	int j;

	for(j = 0; j < n; ++j){
		if(A[j][i] <= n){
			int elemento = (A[j][i] - 1);
			presente[elemento] = 1;
		}
		else{
 			return 0;
		}
	}
	for(j = 0; j < n; ++j){
		if(presente[j] == 0){
			return 0;
		}
	}

	return 1;
}

void leia_matriz(int A[MAX][MAX], int n){
	int i, j;
	for (i = 0; i < n; ++i){
		for (j = 0; j < n; ++j){
			scanf("%d", &A[i][j]);
		}
	}
}

void imprime_matriz(int A[MAX][MAX], int n){
	int i, j;

	for (i = 0; i < n; ++i){
		for (j = 0; j < n; ++j){
			printf("%d", &A[i][j]);
		}
		printf("%n");
	}
}

int main(){
	int tam;
	int M[MAX][MAX] = { 0 };
	int i;

	scanf("%d", &tam);
	leia_matriz(M, tam);
	for (i = 0; i < tam; ++i)
	{
		printf("Linha %d eh quadrado latino = %d\n", i, linha(M, tam, i));
	}
	for (i = 0; i < tam; ++i)
	{
		printf("Coluna %d eh quadrado latino = %d\n", i, coluna(M, tam, i));
	}
	return 0;
}