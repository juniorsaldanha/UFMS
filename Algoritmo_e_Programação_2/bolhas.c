#include <stdio.h>
void lerVetor(int vetor[], int n);
void bolhas(int vetor[], int n);
void troca(int *a, int *b);
int main(){
	int n;
	scanf("%d", &n);
	while(n != 0){
		int vetor[n];
		lerVetor(vetor, n);
		bolhas(vetor, n);
		scanf("%d", &n);
	}
	return 0;
}
void troca(int *a, int *b){
	int x;
	x = *a;
	*a = *b;
	*b = x;
}
void bolhas(int vetor[], int n){
	int i, j = n, sujeito = 0;
	while(j--){
		for (i = 0; i < n-1; ++i) {
			if(vetor[i+1] < vetor[i]){
				troca(&vetor[i+1], &vetor[i]);
				sujeito += 1;
			}
		}
	}
	if(sujeito % 2 != 0) printf("Gilson\n");
	else printf("Jordan\n");
}
void lerVetor(int vetor[], int n){
	int i;
	for(i = 0; i < n; ++i){
		scanf("%d", &vetor[i]);
	}
}
