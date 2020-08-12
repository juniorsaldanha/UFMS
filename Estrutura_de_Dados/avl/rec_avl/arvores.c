#include <stdio.h>
#include <stdlib.h>
#include "arvores.h"
int max(int a, int b){
	return a > b ? a : b;
}
int altura(tnode *a){
	if(a != NULL) return a->h;
	else return -1;
}
void avl_constroi(tarv * parv,int (*cmp)(const void *a, const void *b)){
	parv->raiz = NULL;
	parv->compara = cmp;
}
void Right(tnode **PointerNode){
	tnode *x, *y, *b;
	int h;
	x = *PointerNode;
	y = x->esq;
	b = y->dir;

	x->esq = b;
	y->dir = x;
	*PointerNode = y;

	x->h = max(altura(x->dir),altura(x->esq)) + 1;
    y->h = max(altura(y->dir),altura(y->esq)) + 1;
}
void Left(tnode **PointerNode){
	tnode *x, *y, *b;
	int h;	
	y = *PointerNode;
	x = y->dir;
	b = x->esq;

	x->esq = y;
	y->dir = b;
	*PointerNode = x;
	
	x->h = max(altura(x->dir),altura(x->esq)) + 1; 
    y->h = max(altura(y->dir),altura(y->esq)) + 1; 
}
void rebalancear(tnode **ppnode){
	int h_pai, h_filhos;
	tnode *p, *filho;
	p = *ppnode;
	h_pai = (altura(p->esq) - altura(p->dir));
	if(h_pai == 2){
		filho = p->esq;
		h_filhos = (altura(filho->esq) - altura(filho->dir));
		if(h_filhos == -1) Left(&(p->esq));
		Right(ppnode);
	}else if(h_pai == -2){
		filho = p->dir;
		h_filhos = (altura(filho->esq) - altura(filho->dir));
		if(h_filhos == 1) Right(&(p->dir));
		Left(ppnode);
	}
}
int _avl_insere(tarv *PointerArv, tnode **PointerNode, void *reg){
	int ret = 1;
	if(*PointerNode == NULL){
		*PointerNode = (tnode *)malloc(sizeof(tnode));
		(*PointerNode)->reg = reg;
		(*PointerNode)->esq = (*PointerNode)->esq = NULL;
		(*PointerNode)->h = 0;
	}else{
		if(PointerArv->compara((*PointerNode)->reg, reg) > 0){
			ret = _avl_insere(PointerArv, &((*PointerNode)->esq), reg);
		}else{
			ret = _avl_insere(PointerArv, &((*PointerNode)->dir), reg);
		}
		(*PointerNode)->h = max(altura((*PointerNode)->esq), altura((*PointerNode)->dir))+1;
		rebalancear(PointerNode);
	}
	return ret;
}
int abb_insere(tarv * parv, void * preg){
	return _avl_insere(parv, &(parv->raiz), preg);
}
int avl_insere(tarv * parv, void * preg){
	return _avl_insere(parv, &(parv->raiz), preg);
}