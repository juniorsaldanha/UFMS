#include <stdio.h>
int resto;
int promocao(int chocolates, int embalagens){
	if(chocolates == 0 && resto < embalagens){
		return chocolates;
	}
	else{
		if(resto >= embalagens){
			int aux = resto;
			resto = 0;
			chocolates += promocao(aux, embalagens);
			return chocolates;
		}
		resto += (chocolates % embalagens);
		chocolates /= embalagens;
		chocolates += promocao(chocolates, embalagens);
		return chocolates;
	}
}
int main(){
	int d, p, e;
	scanf("%d%d%d", &d, &p, &e);
	while(d && p && e != 0){
		int chocolates = d/p;
		resto = 0;
		printf("%d ", chocolates + promocao(chocolates, e));
		printf("%d\n", resto);
		resto = 0;
		scanf("%d %d %d", &d, &p, &e);
	}
	return 0;
}