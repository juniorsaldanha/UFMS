#include <stdio.h>
void lerVetor(int vetor[], int n){
	int i;
	for(i = 0; i < n; ++i){
		scanf("%d", &vetor[i]);
	}
}
void troca(int *a, int *b){
	int x;
	x = *a;
	*a = *b;
	*b = x;
}
void selection_sort(int vetor[], int n){
	int i, j, menor, cont = 0;
	for(i = 0; i < n-1; ++i){
		menor = i;
		for(j = i+1; j < n; ++j){
			if (vetor[menor] > vetor[j]){
				menor = j;
			}
		}
		if(i != menor){
			troca(&vetor[menor], &vetor[i]);
			cont += 1;
		}
	}
	printf("%d\n", cont);

}
int main(){
	int k, n;
	scanf("%d", &k);
	while(k--){
		scanf("%d", &n);
		int vetor[n];
		lerVetor(vetor, n);
		selection_sort(vetor, n);
	}
	return 0;
}