#include <stdio.h>
#include <stdlib.h>
#include "arvores.h"

#define DDIR 1
#define DESQ -1

typedef struct _reg{
	int rga;
}treg;

void rotate_right(tnode **pnode){
	tnode *p, *pesq, *b, *aux;
	p 		= *pnode;
	pesq	= p->esq;
	b		= pesq->dir;

	p->esq 		= b;
	pesq->dir	= p;
	*pnode		= pesq;

	if(b != NULL) b->pai = p;

	pesq->pai	= p->pai;
	p->pai		= pesq;
}
void rotate_left(tnode **pnode){
	tnode *p, *pdir, *b, *aux;
	p 		= *pnode;
	pdir 	= p->dir;
	b 		= pdir->esq;

	p->dir 		= b;
	pdir->esq 	= p;
	*pnode		= pdir;

	if(b != NULL) b->pai = p;

	pdir->pai = p->pai;
	p->pai = pdir;
}
int get_cor(tnode *p){
	return (!p) ? PRETO : p->cor;
}
int _fix_up(tarv *parv, tnode *filho){
	tnode *pai, *avo, *tio;
	tnode **pAvo;
	int seta_pai, seta_filho;
	pai = filho->pai;
	while(get_cor(pai) == VERMELHO){
		avo = pai->pai;
		/*Esses 3 ifs verifica as setas para o pai e para o filho. Assim podemos determinar se vai ter cotovelo ou nao, e determinar o tio*/
		if(pai->esq == filho) seta_filho = DESQ;
		else seta_filho = DDIR;
		if(avo->esq == pai) seta_pai = DESQ;
		else seta_pai = DDIR;
		if(seta_pai == DESQ) tio = avo->dir;
		else tio = avo->esq;

		if(get_cor(tio) == VERMELHO){/*Caso 1 - "tio" sendo vermelho*/
			tio->cor = pai->cor = PRETO;
			avo->cor = VERMELHO;
			filho	 = avo;
			pai 	 = filho->pai;
		}else{/*Casos onde o tio nao é vermelho*/
			if(seta_pai * seta_filho < 0){/*Caso 2, onde temos cotovelo*/
				if(seta_filho == DESQ) rotate_right(&avo->dir);
				else rotate_left(&avo->esq);
			}
			
			/*Esse if-else encontra o ponteiro de ponteiro do avo*/
			if(parv->raiz == avo){
				pAvo = &(parv->raiz);
			}else{
				if(avo->pai->esq == avo) pAvo = &(avo->pai->esq);
				else pAvo = &(avo->pai->dir);
			}
			if(seta_pai == DESQ)/*Caso 3 - Sem cotovelo*/
				rotate_right(pAvo);
			else
				rotate_left(pAvo);

			avo 			= *pAvo;
			avo->cor 		= PRETO;
			avo->esq->cor 	= avo->dir->cor	= VERMELHO;
			pai 			= avo; /*Necesserio essa atribuição, pois temos q ir subindo na arv para verificar 
			os outro casos acima, assim o pai sera atualizado e reverificado a cor se é vermelho ou n, e se necessario,
			reexecutar todo o codigo do while.*/
		}
	}
}
void rb_constroi(tarv * parv,int (*cmp)(const void *a, const void *b)){
	parv->raiz 		= NULL;
	parv->compara	= cmp;
}
int rb_insere(tarv * parv, void * preg){
	tnode *filho = parv->raiz;
	tnode *pai = parv->raiz;
	int ret;
	while(filho){
		pai	= filho;
		if(parv->compara(filho->reg, preg) < 0)
			filho = filho->dir;
		else
			filho = filho->esq;
	}
	filho = (tnode *)malloc(sizeof(tnode));
	if(!filho) ret = 0;
	else{
		filho->reg = preg;
		filho->esq = filho->dir = NULL;
		filho->cor = VERMELHO;
		filho->pai = pai;
		if(!parv->raiz) parv->raiz = filho;
		else{
			if(parv->compara(pai->reg, preg) < 0)
				pai->dir = filho;
			else
				pai->esq = filho;
			ret = _fix_up(parv, filho);/*funcao que recalibra a tree*/
		}
	}
	parv->raiz->cor = PRETO;
	return ret;
}