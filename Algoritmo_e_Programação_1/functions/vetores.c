#include <stdio.h>
#define MAX 100
/*		Exemploe de como será chamada as funções acima.

			nome do vetor devera ser substituido no texto "vetor".
			tamanho do vetor devera ser substituido no texto "N".
	ler_vetor(vetor, N);
	imprimir_vetor(vetor, N);
*/
void ler_matriz(int v[MAX][MAX], int x, int y){
	int i, j;
	for (i = 0; i < x; ++i){
		for (j = 0; j < y; ++j){
			scanf("%d", &v[j][i]);
		}
	}
}
void print_matriz(int v[MAX][MAX], int x, int y){
	int i, j;
	for (i = 0; i < x; ++i){
		for (j = 0; j < y; ++j){
			printf("%d ", v[j][i]);
		}
		printf("\n");
	}
}
int ler_vetor(int A[], int n){
	int i;

	for(i = 0; i < n; ++i){
		scanf("%d", &A[i]);
	}
	return 0;
}
int imprimir_vetor(int A[], int n){
	int i;

	for(i = 0; i < n; ++i){
		printf("%2d", A[i]);
	}
	printf("\n");
	return 0;
}
int ordenar_vetor_booble(int A[], int n){ //Metodo lento, aconselhavel utilizar Quicksorte(qsort)
	int aux = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-1; ++j)
		{
			if(A[j] > A[j+1]){
				aux = A[j+1];
				A[j+1] = A[j];
				A[j] = aux;
			}
		}
	}
	return 0;
}
int verificar_quant_elementos_distintos(int A[], int n){
	int value = 1;
	for (int i = 0; i < (n-1); ++i)
	{
		if(i <= (n-1) && A[i] != A[i+1]){
			++value;
		}
	}
	return value;
}
