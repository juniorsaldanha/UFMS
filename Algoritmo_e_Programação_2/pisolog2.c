#include <stdio.h>
int logaritmo(int n){
	if(n == 1){
		return 0;
	}
	else{
		n /= 2;
		return (1 + logaritmo(n));
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
			printf("%d\n", logaritmo(aux));
		}
	}
	return 0;
}