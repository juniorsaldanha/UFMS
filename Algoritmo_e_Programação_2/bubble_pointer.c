#include <stdio.h>
void lerVetor(int *v, int n){
	int* p;
	int i;
	p = v;
	for(i = 0; i < n; ++i)
		scanf("%d", (p+i));
}
void printVetor(int *v, int n){
	int* p;
	int i;
	p = v;
	for(i = 0; i < n; ++i)
		printf("%d ", *(p+i));
	printf("\n");
}
void troca(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}
int bubble_pointer(int *v, int n){
	int i, m, count = 0;
	int* p;
	p = v;
	for(m = n; m > 0; --m){
		for (p = v; p < (v+n)-1; ++p){
			if(*(p) > *(p+1)){
				troca((p), (p+1));
				count += 1;
			} 
		}
	}
	return count;
}
int main(){
	int k;
	scanf("%d", &k);
	while(k--){
		int n;
		scanf("%d", &n);
		int v[n];
		lerVetor(v, n);
		printf("%d\n", bubble_pointer(v, n));
		//printVetor(v, n);
	}
	return 0;
}