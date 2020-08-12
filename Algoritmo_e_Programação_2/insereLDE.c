#include <stdio.h>
#include <stdlib.h>
typedef int ttipo;
typedef struct _node{
	ttipo dado;
	struct _node *dir;struct _node *esq;
}node;
void insere_inicio(node **inicio, node **fim, ttipo value){
	node *new_ = malloc(sizeof(node));
	new_->dado = value;
	if(*inicio == NULL){
		*inicio = *fim = new_;
		new_->esq = new_->dir = NULL;
	}else{
		new_->dir = *inicio;
		new_->esq = NULL;
		(*inicio)->esq = new_;
		*inicio = new_;
	}
}
void insere_fim(node **inicio, node **fim, ttipo value){
	node *new_ = malloc(sizeof(node));
	new_->dado = value;
	if(*fim == NULL){
		*inicio = *fim = new_;
		new_->esq = new_->dir = NULL;
	}else{
		new_->esq = *fim;
		new_->dir = NULL;
		(*fim)->dir = new_;
		*fim = new_;
	}
}
void print_inicio(node **inicio){
	node *temp = *inicio;
	for(;temp != NULL;temp=temp->dir){
		printf("%d ", temp->dado);
	}
	printf("\n");
}
void print_fim(node **fim){
	node *temp = *fim;
	for(;temp != NULL;temp = temp->esq){
		printf("%d ", temp->dado);
	}
	printf("\n");
}
int main(){
	int command;ttipo dado;
	node *inicio = NULL;node *fim = NULL;
	while(scanf("%d", &command)){
		if(command == 0) break;
		else if(command == 1){
			scanf("%d", &dado);
			insere_inicio(&inicio, &fim, dado);
		}else if(command == 2){
			scanf("%d", &dado);
			insere_fim(&inicio, &fim, dado);
		}else if(command == 3){
			print_inicio(&inicio);
		}else if(command == 4){
			print_fim(&fim);
		}
	}
	return 0;
}