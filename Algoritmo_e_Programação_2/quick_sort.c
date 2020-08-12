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
		pivo = particiona(v, e, d);
		quicksort(v, e, pivo-1);
		quicksort(v, pivo+1, d);
	}
}
int main(){
	int n = 1;
	while(n != 0){
		scanf("%d", &n);
		if(n == 0) break;
		int v[n], i;
		ler_vetor(v, n);
		printf("Vetor Original:\n");
		print_vetor(v, n);
		quicksort(v, 0, n-1);
		printf("Vetor Ordenado:\n");
		print_vetor(v, n);
		printf("\n");
	}
	return 0;
}