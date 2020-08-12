#include <stdio.h>
#include <stdlib.h>

typedef struct damn{
	char letra;
	struct damn *prox;
} alfa;

void printaLista(alfa *p){
	p = p->prox;
	while(p->prox != NULL){
		printf("%c", p->letra);
		p = p->prox;
	}
	printf("%c\n", p->letra);
}

alfa *insere(char x, alfa *p){
	alfa *nova = malloc(sizeof(alfa));
	nova->letra = x;
	nova->prox = p->prox;
	p->prox = nova;

	return nova;
}

int main(){
	int n, i;
	char c[100];
	scanf("%d", &n);
	while(n--){
		alfa cabeca;
		cabeca.prox = NULL;
		alfa *atual = &cabeca;
		scanf("%s", c);
		for(i = 0; c[i] != '\0'; ++i){
			if(c[i] == '['){
				atual = &cabeca;
			}
			else if(c[i] == ']'){
				while(atual->prox != NULL){
					atual = atual->prox;
				}
			}
			else{
				atual = insere(c[i], atual);
			}
		}
		printaLista(&cabeca);
	}
	return 0;
}