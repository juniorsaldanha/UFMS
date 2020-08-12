#include <stdio.h>
void print_vetor(int v[], int n){
	int i;
	for(i = 0; i < n; ++i){
		printf("%d ", v[i]);
	}
	printf("\n");
}
void ler_vetor(int v[], int n){
	int i;
	for(i = 0; i < n; ++i){
		scanf("%d", &v[i]);
	}
}
void troca(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}
int particiona(int v[], int e, int d){
	int pivo = v[e];
	int i = e+1, j = d;
	while(i <= j){
		if(v[i] <= pivo) ++i;
		else if(v[j] > pivo) --j;
		else{
			troca(&v[i], &v[j]);
			++i, --j;
		}
	}
	troca(&v[e], &v[j]);
	return j;
}
void quicksort(int v[], int e, int d){
	int pivo;
	if(e < d){
		print_vetor(v, 5);
		pivo = particiona(v, e, d);
		quicksort(v, e, pivo-1);
		quicksort(v, pivo+1, d);
	}
}
void insertionsort(int v[], int n){
	int i, j;
	for(i = 0; i < n-1; ++i){
		for(j = i+1; j > 0; --j){
			if(v[j] < v[j-1]) troca(&v[j], &v[j-1]);
		}
	}
}
void selectionsort(int v[], int n){
	int i, j, menor;
	for(i = 0; i < n-1; ++i){
		menor = i;
		for(j = i+1; j < n; ++j){
			if(v[menor] > v[j]) menor = j;
		}
		if(i != menor){
			troca(&v[i], &v[menor]);
		}
	}
}
int main(){
	int n = 1;
	while(n != 0){
		
		scanf("%d", &n);
		if(n == 0) break;
		int v[n], i;
		ler_vetor(v, n);
		printf("1 - Selection Sort\n2 - Insertion Sort\n3 - Quick Sort\n");
		int opcao;
		scanf("%d", &opcao);
		printf("Vetor Original:\n");
		print_vetor(v, n);
		if(opcao == 1) selectionsort(v, n);
		else if(opcao == 2) insertionsort(v, n);
		else if(opcao == 3) quicksort(v, 0, n-1);
		//quicksort(v, 0, n-1);
		//insertionsort(v, n);
		//selectionsort(v, n);
		printf("Vetor Ordenado:\n");
		print_vetor(v, n);
		printf("\n");
	}
	return 0;
}