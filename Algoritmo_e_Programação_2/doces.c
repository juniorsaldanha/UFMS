#include <stdio.h>
void lerVetor(int v[], int n);
void desce(int v[], int n, int i);
void sobe(int v[], int n, int i);
void constroeheap(int v[], int n);
int pai(int i);
int fesq(int i);
int fdir(int i);
void troca(int *a, int *b);
void carai(int v[], int n, int doce, int *count);
int main(){
	int n, k, count = 0;
	scanf("%d %d", &n, &k);
	int docuras[n];
	lerVetor(docuras, n);
	carai(docuras, n, k, &count);
	return 0;
}
void lerVetor(int v[], int n){
	int i;
	for (i = n-1; i >= 0; --i){
		scanf("%d", &v[i]);
	}
}
void troca(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}
int pai(int i){
	int ret;
	if(i == 0) ret = 0;
	else ret=(i-1)/2;
	return ret;
}
int fesq(int i){

	return (2*i)+1;
}
int fdir(int i){

	return (2*i)+2;
}
void desce(int v[], int n, int i){
	int e, d, imax;
	e = fesq(i), d = fdir(i), imax = i;
	if(e < n && v[e] < v[imax]) imax = e;
	if(d < n && v[d] < v[imax]) imax = d;
	if(imax != i){
		troca(&v[imax], &v[i]);
		desce(v, n, imax);
	}
}
void sobe(int v[], int n, int i){
	while(v[pai(i)] > v[i]){
		troca(&v[pai(i)], &v[i]);
		i = pai(i);
	}
}
void constroeheap(int v[], int n){
	int i = pai(n-1);
	while(i >= 0){
		desce(v, n, i);
		--i;
	}
}
void carai(int v[], int n, int doce, int *count){
	int menor = n-1, secondmenor = n-2;
	if(n > 0 && v[menor] < doce){
		v[secondmenor] = (v[menor] + 2*v[secondmenor]);
		*count += 1;
		sobe(v, n-1, n-1);
		carai(v, n-1, doce, count);
	}
	else if(v[menor] >= doce){
		printf("count %d\n", *count);
		for(int i = 0;i < 5; ++i){
			printf("%d ", v[i]);
		}
		printf("\n");
	}
	else{
		printf("-1\n");
		return;
	} 
}