#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void preencherVetorRadon(int vetor[], int n){
	int i;
	srand((unsigned)time(NULL));
	for(i = 0; i < n; ++i){
		vetor[i] = rand()%n+1;
	}
}
void printVetor(int vetor[], int n){
	int i;
	for(i = 0; i < n; ++i){
		if(i % 10 == 0 && i != 0){
			printf(" \\n\n");
		}
		printf("%4d ", vetor[i]);
	}
	printf("\n");
}
void troca(int* a, int* b){
	int c = *a;
	*a = *b;
	*b = c;
}
int particiona(int vetor[], int e, int d){
	int pivo = vetor[e];
	int i = e+1, j = d;
	while(i <= j){
		if(vetor[i] <= pivo) ++i;
		else if(vetor[j] > pivo) --j;
		else{
			troca(&vetor[i], &vetor[j]);
			++i, --j;
		}
	}
	troca(&vetor[e], &vetor[j]);
	return j;
}
void quickSort(int vetor[], int e, int d){
	int pivo;
	if(e < d){
		pivo = particiona(vetor, e, d);
		quickSort(vetor, e, pivo-1);
		quickSort(vetor, pivo+1, d);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int vetor[n];
	preencherVetorRadon(vetor, n);
	printf("Vetor Desordenado:\n");
	printVetor(vetor, n);
	quickSort(vetor, 0, n-1);
	printf("Vetor Ordenado:\n");
	printVetor(vetor, n);
	return 0;
}	