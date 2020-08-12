#include <stdio.h>
int primo(int unsigned a){
	int b;

	for (b = 2; b < a; ++b)
	{
		if(a % b == 0){
			return 0;
		}
	}
	return 1;
}

/*
	Utilizar codigo abaixo para chamar a função.

#include <stdio.h>
#include "AlgProg1\functions\NumPrimos.c"
int main(){
	int unsigned X;
	int N, m;
	scanf("%d", &N);
	
	while(N > 0){
		scanf("%d", &X);
		m = primo(X);
		if(m == 0) printf("Not Prime\n");
		else printf("Prime\n");
		--N;
	}
	return 0;
}
*/