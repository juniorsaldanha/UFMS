#include <stdio.h>
void funcao(int n){
	if(n == 1) printf("%d", n);

	else if(n%2 == 0){
		funcao(n/2);
		printf(" %d", n);
	}
	else if(n%2 != 0){
		funcao((n*3)+1);
		printf(" %d", n);
	}
}
int main(){
	int k, i, aux;
	scanf("%d", &k);
	int n[k];
	for (i = 0; i < k; ++i){
		scanf("%d", &n[i]);
		aux = n[i];
		
		if(aux == 1) printf("%d\n", aux);
		else if(aux != 1){
			funcao(aux);
			printf("\n");
		}
	}
	return 0;
}
