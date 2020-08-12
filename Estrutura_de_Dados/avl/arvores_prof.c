#include <stdio.h>
#include <stdlib.h>
#include "arvores.h"


typedef struct _pilha{
	tnode **node;
	struct _pilha *next;
}tpilha;

void empilha(tpilha **ppilha, tnode **node){
	tpilha *new = (tpilha *)(malloc(sizeof(tpilha)));
	new->node = node;
	new->next = *ppilha;
	*ppilha = new;
}

tnode **desempilha(tpilha **ppilha){
	tpilha *aux;
	tnode **ret = NULL;
	if(*ppilha != NULL){
		aux = (*ppilha);
		*ppilha = (*ppilha)->next;
		ret = aux->node;
		free(aux);
	}
	return ret;
}

int max(int a, int b){
	return a > b ? a : b;
}

int altura(tnode *pnode){
	int ret = -1;
	if(pnode != 0){
		ret = pnode->h;
	}
	return ret;
}

void RD(tnode **pnode){
	tnode *x, *y, *b;
	int h;
	x = *pnode;
	y = x->esq;
	b = y->dir;

	x->esq = b;
	y->dir = x;
	*pnode = y;

	x->h = max(altura(x->dir),altura(x->esq)) + 1;
    y->h = max(altura(y->dir),altura(y->esq)) + 1;
}

void RE(tnode **pnode){
	tnode *x, *y, *b;
	int h;	
	y = *pnode;
	x = y->dir;
	b = x->esq;

	x->esq = y;
	y->dir = b;
	*pnode = x;
	
	x->h = max(altura(x->dir),altura(x->esq)) + 1; 
    y->h = max(altura(y->dir),altura(y->esq)) + 1; 
}
void _rebalance(tnode ** pnode){
	int fb, fbf;
	tnode *p, *filho;
	p = *pnode;
	fb = altura(p->esq) - altura(p->dir);
	if(fb == 2){
		filho = p->esq;
		fbf = altura(filho->esq) - altura(filho->dir);
		if(fbf == -1){
			RE(&(p->esq));
		}
		RD(pnode);
	}
	else if(fb == -2){
		filho = p->dir;
		fbf = altura(filho->esq) - altura(filho->dir);
		if(fbf == 1){
			RD(&(p->dir));
		}
		RE(pnode);	
	}

}

void avl_constroi(tarv * parv,int (*cmp)(const void *a, const void *b)){
	parv->raiz = 0;
	parv->compara = cmp;
}

//código novo da avl


void abb_constroi(tarv * parv, int (*cmp)(const void *a, const void *b)){
	parv->raiz = NULL;
	parv->compara = cmp;
}

int _insere_arv(tarv *parv, tnode **pnode, void * preg){
	/*essa função é chamada pela função __int inserir__.
	a ideia desta função é criar um elemento tnode e
	guardar __preg__ em tnode. */
	int ret = 1;
	if(*pnode == 0){
		*pnode = (tnode *)malloc(sizeof(tnode));
		if(*pnode == 0)
			/*caso onde acontece algum problema na alocação
			dinâmica*/
			ret = 0;
		else{
			/*se na chamada recursiva mandarmos um NULL
			como segundo parâmetro criamos aqui e inicia-
			lizamos as variáveis do meu registro PNODE novo*/
			(*pnode)->reg	= preg;
			(*pnode)->esq	= (*pnode)->dir	= 0;
			(*pnode)->h		= 0;
		}
	}
	else{
		/*	enquanto não chegarmos em um local NULL para
			criar o novo PNODE nós faremos chamadas recursivas
			com base na nossa função COMPARA, seja qual for
			o resultado garantimos que correrá bem
		*/
		if(parv->compara((*pnode)->reg, preg) > 0){
			ret = _insere_arv(parv, &((*pnode)->esq), preg);
		}
		else{
			ret = _insere_arv(parv, &((*pnode)->dir), preg);
		}
		/*
			chama rebalanceamento nas outras instancias
			da recursão para corrigir a altura que foi alterada
		*/
		(*pnode)->h = max(altura((*pnode)->esq), altura((*pnode)->dir)) + 1;
		_rebalance(pnode);
	}
	return ret;
}

int abb_insere(tarv * parv, void * preg){
	return _insere_arv(parv, &(parv->raiz), preg);
}

int avl_insere(tarv * parv, void * preg){
    return _insere_arv(parv,&(parv->raiz),preg);
}


void * _busca_node(tarv *parv, tnode ** pnode, void * preg){
	void * ret;
	if(*pnode == 0){
		ret = 0;
	}
	else if(parv->compara((*pnode)->reg, preg) == 0)
	{
		ret = (*pnode)->reg;
	}
	else{
		if(parv->compara((*pnode)->reg, preg) > 0){
			ret = _busca_node(parv, &((*pnode)->esq), preg);
		}
		else{
			ret = _busca_node(parv, &((*pnode)->dir), preg);
		}
	}
	return ret;
}

void * abb_busca(tarv * parv, void *preg){
	return _busca_node(parv, &(parv->raiz), preg);
}

tnode ** busca_pont(tarv * parv, tnode ** pnode, void * preg){
	tnode ** ret;
	if 		(*pnode == NULL){
			ret = 0;
	}
	else if (parv->compara((*pnode)->reg, preg) == 0){
		ret = pnode;
	}
	else if (parv->compara((*pnode)->reg, preg) > 0){
		ret = busca_pont(parv, &((*pnode)->esq), preg);
	}
	else{
		ret = busca_pont(parv, &((*pnode)->dir), preg);
	}
	return ret;
}

int remove_raiz(tnode **pnode){
	int ret = 0;
	tnode * aux;
	if(*pnode != NULL){
		if 			((*pnode)->dir == NULL && (*pnode)->esq == NULL){
			//	caso onde o nó não tem filhos.
			/*	damos FREE no conteúdo do nó e depois disso
				no próprio nó, depois dizemos que ele aponta
				para nulo e é suficiente
			*/
			free((*pnode)->reg);
			free(*pnode);
			*pnode = NULL;
			ret = 1;
		}
		else if 	((*pnode)->dir == NULL && (*pnode)->esq != NULL){
			//caso onde o nó tem filho apenas à esquerda
			/*	damos free no conteúdo, no nó e dpois dizemos
				que o nó pai do que estamos tentando remover
				vai apontar para este filho único da esquerda
			*/
			free((*pnode)->reg);
			aux = *pnode;
			*pnode = (*pnode)->esq;
			free(aux);
			ret = 1;
		}
		else if 	((*pnode)->dir != NULL && (*pnode)->esq == NULL){
			free((*pnode)->reg);
			aux = *pnode;
			*pnode = (*pnode)->dir;
			free(aux);
			ret = 1;
		}
		else{
			//	terceiro caso, onde precisamos encontrar sucessor
			/*	aqui a solução é encontrar o sucessor do nó,
				fazer o transplante e depois dar free no nó
			*/
			aux = (*pnode)->dir;
			tnode ** paux = &((*pnode)->dir);
			while(aux->esq != 0){
				paux = &(aux->esq);
				aux = aux->esq;
			}
			free((*pnode)->reg);
            (*pnode)->reg = aux->reg;
            *paux = aux->dir;
            free(aux);
            ret = 1;
		}
	}
	return ret;
}

int abb_remove(tarv * parv, void *preg){
	int ret = 0;
	tnode **aux = busca_pont(parv, &(parv->raiz), preg);
	if(aux != NULL){
		ret = remove_raiz(aux);
	}
	return ret;
}

void _destruir(tnode *pnode){
	if(pnode != NULL){
		_destruir(pnode->esq);
		_destruir(pnode->dir);
		free(pnode->reg);
		free(pnode);
	}
}

int abb_destroi(tarv * parv){
	int ret = 0;
	if(parv->raiz != NULL){
		_destruir(parv->raiz);
		ret = 1;
	}
	return ret;
}

int _remove_arv(tarv *parv, tnode **pnode, void *preg){
	int ret;
	tnode *aux;
	tnode **paux;
	tnode **pai;
	tpilha *pilha;
	if(*pnode == NULL){
		ret = 0;
	}else{
		if(parv->compara(((*pnode)->reg), preg) > 0)
			ret = _remove_arv(parv, &((*pnode)->esq), preg);
		else if(parv->compara(((*pnode)->reg), preg) < 0)
			ret = _remove_arv(parv, &((*pnode)->dir), preg);
		else{
			if((*pnode)->dir == NULL && (*pnode)->esq == NULL){ /*Caso 1 - Não tem filhos*/
				free((*pnode)->reg);
				free(*pnode);
				*pnode 	= NULL;
			}else if((*pnode)->dir != NULL && (*pnode)->esq == NULL){ /*Caso 2 - Tem apenas filho direito*/
				free((*pnode)->reg);
				aux 	= (*pnode);
				*pnode 	= aux->dir;
				free(aux);
			}else if((*pnode)->dir == NULL && (*pnode)->esq != NULL){ /*Caso 2 - Tem apenas filho esquerdo*/
				free((*pnode)->reg);
				aux 	= (*pnode);
				*pnode 	= aux->esq;
				free(aux);
			}else{ /*Caso 3 - Tem os dois filhos*/
				pilha = NULL;
				empilha(&pilha, pnode);
				paux	= &((*pnode)->dir);
				aux		= (*pnode)->dir;
				while(aux->esq != NULL){
					empilha(&pilha, paux);
					paux = &(aux->esq);
					aux = aux->esq;
				}
				free((*pnode)->reg);
				(*pnode)->reg = aux->reg;
				*paux = aux->dir;
				free(aux);
				pai = desempilha(&pilha);
				while(pai != NULL){
					(*pai)->h = max(altura((*pai)->esq), altura((*pai)->dir))+1;
					_rebalance(pai);
					pai = desempilha(&pilha);
				}
			}
		}
		if(*pnode != NULL){
			(*pnode)->h = max(altura((*pnode)->esq), altura((*pnode)->dir));
			_rebalance(pnode);
		}
	}
	return ret;
}

int avl_remove(tarv * parv, void * preg){
    return _remove_arv(parv,&(parv->raiz),preg);
}