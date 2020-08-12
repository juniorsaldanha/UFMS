#include <stdio.h>
//Codigo elaborado pelo Junior Saldanha , apenas testando atualização automatica do gitlab.
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
void print_vetor(int vetor[], int n){
	int i;
	for(i = 0; i < n; ++i){
		printf("%d ", vetor[i]);
	}
	printf("\n");
}
void insertion_sort(int vetor[], int n){
	int i, j;
	for(i = 0; i < n-1; ++i){
		for(j = i+1; j > 0; --j){
			if(vetor[j] < vetor[j-1]) troca(&vetor[j], &vetor[j-1]);
		}
		print_vetor(vetor, n);
	}
}
void insertionSort(int original[], int length) {
	int i, j, atual;

	for (i = 1; i < length; i++){
		atual = original[i];
		for (j = i - 1; (j >= 0) && (atual < original[j]); j--) {
			original[j + 1] = original[j];
        }
		original[j+1] = atual;
	}

}
int main(){
	int k, n;
	scanf("%d", &k);
	while(k--){
		scanf("%d", &n);
		int vetor[n];
		lerVetor(vetor, n);
		printf("Desordenado:\n");
		print_vetor(vetor, n);
		//insertion_sort(vetor, n);
		insertionSort(vetor, n);
		printf("Ordenado:\n");
		print_vetor(vetor, n);
		printf("\n");
	}
	return 0;
}