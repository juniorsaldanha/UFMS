#include <stdio.h>
void troca(int *a,int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
	return;
}
void permuta(int *v, int j, int n, int *k){
	int i;
	if(j == n - 1){
		k[0] = k[0]-1;
		if(k[0] == 0){
			for (i = 0; i < n; ++i)
			{
				printf("%d", v[i]);
			}
			printf("\n");
		}
	}
	else{
		for(i = j; i < n; i++){
			troca(&v[i], &v[j]);
			permuta(v, j + 1, n, k);
			troca(&v[i], &v[j]);
		}
	}
}
int main(){
	int n, t, k[0], i;
	scanf("%d", &n);
	while(n-- > 0){
		scanf("%d%d", &t, &k[0]);
		int v[t];
		for (i = 0; i < t; ++i)
		{
			v[i] = i + 1;
		}
		permuta(v, 0, t, k);

	}
	

	return 0;
}