#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"arvores.h"


typedef struct _reg{
    int id;
    int idade;
}treg;

int compara(const void *a, const void *b){
    return (*(treg *)a).id - (*(treg *)b).id; 
}

treg * aloca_reg(int id){
    treg * aux = (treg *)malloc(sizeof(treg));
    aux->id = id;
    return aux;
}

void   test_construtor(){
    int a,b;
    tarv arv;
    avl_constroi(&arv,&compara);
    a = 10;
    b = 20;
    assert(arv.raiz == NULL);
    assert(arv.compara(&a,&b) == -10);
    assert(arv.compara(&b,&a) == 10);
    assert(arv.compara(&b,&b) == 0);
    assert(arv.compara(&a,&a) == 0);
    printf("Construcao OK\n");
}

void test_insere(){
    tarv arv;
    treg * aux = (treg *)malloc(sizeof(treg));

    avl_constroi(&arv,&compara);
    
    avl_insere(&arv,aloca_reg(10));

    assert(arv.raiz->esq == NULL);
    aux->id = 10;assert(compara(arv.raiz,aux));
    assert(arv.raiz->dir == NULL);
   
    avl_insere(&arv,aloca_reg(20)); 
    aux->id = 10;assert(compara(arv.raiz,aux));
    assert(arv.raiz->esq == NULL);
    
    assert(arv.raiz->dir->esq == NULL);
    aux->id = 20;assert(compara(arv.raiz->dir,aux));
    assert(arv.raiz->dir->dir == NULL);


    avl_insere(&arv,aloca_reg(30)); 

    assert(arv.raiz->esq->dir == NULL);
    aux->id = 10;assert(compara(arv.raiz->esq,aux));
    assert(arv.raiz->esq->esq == NULL);
 
    aux->id = 20;assert(compara(arv.raiz,aux));
    
    assert(arv.raiz->dir->dir == NULL);
    aux->id = 30;assert(compara(arv.raiz->dir,aux));
    assert(arv.raiz->dir->esq == NULL);

   

    avl_insere(&arv,aloca_reg(40)); 
    assert(arv.raiz->esq->esq == NULL);
    aux->id = 10;assert(compara(arv.raiz->esq,aux));
    assert(arv.raiz->esq->dir == NULL);

    aux->id = 20;assert(compara(arv.raiz,aux));
    
    aux->id = 30;assert(compara(arv.raiz->dir,aux));
    assert(arv.raiz->dir->esq == NULL);
    
    assert(arv.raiz->dir->dir->dir == NULL);
    aux->id = 40;assert(compara(arv.raiz->dir->dir,aux));
    assert(arv.raiz->dir->dir->esq == NULL);
    
    avl_insere(&arv,aloca_reg(35)); 
    
    assert(arv.raiz->esq->esq == NULL);
    aux->id = 10;assert(compara(arv.raiz->esq,aux));
    assert(arv.raiz->esq->dir == NULL);
    

    aux->id = 20;assert(compara(arv.raiz,aux));
    
    aux->id = 35;assert(compara(arv.raiz->dir,aux));
    
    assert(arv.raiz->dir->esq->esq == NULL);
    aux->id = 30;assert(compara(arv.raiz->dir->esq,aux));
    assert(arv.raiz->dir->esq->dir == NULL);
    
    assert(arv.raiz->dir->dir->esq == NULL);
    aux->id = 40;assert(compara(arv.raiz->dir->dir,aux));
    assert(arv.raiz->dir->dir->dir == NULL);
 
    avl_insere(&arv,aloca_reg(5)); 
    avl_insere(&arv,aloca_reg(7)); 
   
    assert(arv.raiz->esq->esq->esq == NULL);
    aux->id = 5 ;assert(compara(arv.raiz->esq->esq,aux));
    assert(arv.raiz->esq->esq->dir == NULL);
     
    aux->id = 7 ;assert(compara(arv.raiz->esq,aux));

    assert(arv.raiz->esq->dir->esq == NULL);
    aux->id = 10;assert(compara(arv.raiz->esq->dir,aux));
    assert(arv.raiz->esq->dir->dir == NULL);
    
    aux->id = 20;assert(compara(arv.raiz,aux));
   
    assert(arv.raiz->dir->esq->esq == NULL);
    aux->id = 30;assert(compara(arv.raiz->dir->esq,aux));
    assert(arv.raiz->dir->esq->dir == NULL);
   
    aux->id = 35;assert(compara(arv.raiz->dir,aux));
    
    assert(arv.raiz->dir->dir->esq == NULL);
    aux->id = 40;assert(compara(arv.raiz->dir->dir,aux));
    assert(arv.raiz->dir->dir->dir == NULL);
    
}

int main(void){
    test_construtor();
    test_insere();
    return 0;
}


