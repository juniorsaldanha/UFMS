#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct _node{
	int reg;
	struct _node *esq;
	struct _node *dir;
}tnode;
int insere(tnode ** pnode, int chave){
	if(*pnode == NULL){
		*pnode = malloc(sizeof(tnode));
		(*pnode)->esq = (*pnode)->dir = NULL;
		(*pnode)->reg = chave;
	}else if((*pnode)->reg >= chave){
		insere(&((*pnode)->esq), chave);
	}else{
		insere(&((*pnode)->dir), chave);
	}return 1;
}
void print_arv(tnode *head){
	if(head != NULL){
		print_arv(head->esq);
		printf("%d ", head->reg);
		print_arv(head->dir);
	}
}
int main(){
	int v[] = {10, 20, 7, 14, 22, 13, 9, 0};
	tnode *head = NULL;
	for (int i = 0; i < 8; ++i)	{
		insere(&head, v[i]);
	}
	print_arv(head);printf("\n");
	
	return 0;
}