#include <stdio.h>
#include <stdlib.h>
typedef int ttipo;
typedef struct _node{
	ttipo dado;
	struct _node *dir;struct _node *esq;
}node;

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
void remove_inicio(node **inicio, node **fim){
	node *temp = *inicio;
	if((*inicio) == NULL) return;
	else if(*inicio == *fim){
		(*inicio) = (*fim) = NULL;
		return;
	}
	else{
		(*inicio) = (*inicio)->dir;
		(*inicio)->esq = NULL;
		free(temp);
	}
}
void remove_fim(node **inicio, node **fim){
	node *temp = *fim;
	if((*fim) == NULL) return;
	else if(*inicio == *fim){
		(*inicio) = (*fim) = NULL;
		return;
	}
	else{
		(*fim) = (*fim)->esq;
		(*fim)->dir = NULL;
		free(temp);
	}
}
void print_inicio(node **inicio){
	node *temp = *inicio;
	if((*inicio) == NULL){
		printf("lista vazia\n");
		return;
	}
	for(;temp != NULL;temp=temp->dir){
		printf("%d ", temp->dado);
	}
	printf("\n");
}
void print_fim(node **fim){
	node *temp = *fim;
	if((*fim) == NULL){
		printf("lista vazia\n");
		return;
	}
	for(;temp != NULL;temp = temp->esq){
		printf("%d ", temp->dado);
	}
	printf("\n");
}
int main(){
	int command, n;ttipo dado;
	node *inicio = NULL;node *fim = NULL;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &dado);
		insere_fim(&inicio, &fim, dado);
	}
	while(scanf("%d", &command)){
		if(command == 0) break;
		else if(command == 1){
			remove_inicio(&inicio, &fim);
		}else if(command == 2){
			remove_fim(&inicio, &fim);
		}else if(command == 3){
			print_inicio(&inicio);
		}else if(command == 4){
			print_fim(&fim);
		}
	}
	return 0;
}