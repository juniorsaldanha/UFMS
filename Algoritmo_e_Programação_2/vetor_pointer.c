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
int main(){
	int k;
	scanf("%d", &k);
	while(k--){
		int n;
		scanf("%d", &n);
		int v[n];
		lerVetor(v, n);
		printVetor(v, n);
	}
	return 0;
}