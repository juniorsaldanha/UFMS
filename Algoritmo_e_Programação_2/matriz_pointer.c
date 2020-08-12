#include <stdio.h>
void lerMatriz(int *v, int n){
	int* p;
	for(p = v; p < (v+n); ++p)
		scanf("%d", (p));
}
void printMatriz(int *v, int n, int m){
	int* p;
	int a = n*m, b;
	for(p = v, b = 0; p < (v+a); ++p, ++b){
		if(b == m){
			printf("\n");
			b = 0;
		}
		printf("%d ", *(p));
	}
	printf("\n");
}
int main(){
	int k;
	scanf("%d", &k);
	while(k--){
		int n, m;
		scanf("%d %d", &n, &m);
		int v[n][m];
		int* p;
		p = *v;
		lerMatriz(p, (n*m));
		printMatriz(p, n, m);
		printf("\n");
	}
	return 0;
}