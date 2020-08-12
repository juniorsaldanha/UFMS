#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arvoreb.h"

int menor(int x, int y){
    return x < y ? x : y;
}
tnode *aloca_node(tarv* parv){
    tnode *aux;
    aux = (tnode*)malloc(sizeof(tnode));
    if(aux != NULL){
        aux->n = 0;
        aux->folha = 0;
    }
    return aux;
}
void btree_constroi(tarv * parv, int t){
    parv->t = t;
    parv->raiz = aloca_node(parv);
    parv->raiz->n = 0;
    parv->raiz->folha = TRUE;
}
int btree_split(tarv *parv, tnode *node, int i){
    tnode *x = aloca_node(parv), *y = node->c[i];
    int t = parv->t, j, ret = 0;
    if(x){
        x->folha = y->folha;
        x->n = t-1;
        for(j = 0; j < t - 1; j++)
            x->chaves[j] = y->chaves[j+t];
        if(!y->folha)
            for (j = 0; j < t; j++)
                x->c[j] = y->c[j+t];
        y->n = t - 1;
        for(j = node->n; j >= i + 1; j--)
            node->c[j+1] = node->c[j];
        node->c[i+1] = x;

        for(j = node->n - 1; j >= i; j--)
            node->chaves[j+1] = node->chaves[j];
        node->chaves[i] = y->chaves[t-1];
        node->n++;
        node->folha = FALSE;
        ret = 1;
    }
    return ret;
}
int btree_insere_naocheio(tarv * parv, tnode *node, tchave k){
    int i = node->n, t = parv->t, ret = 1;
    if(node->folha == TRUE){
        for(; i > 0 && k < node->chaves[i-1];i--)
            node->chaves[i] = node->chaves[i-1];
        node->chaves[i] = k;
        node->n = node->n+1;
    }else{
        for(i-- ;i >= 0 && k < node->chaves[i]; --i);
        i++;
        if(node->c[i]->n == 2*t - 1){
            ret = btree_split(parv, node, i);
            if(k > node->chaves[i])
                i++;
        }
        ret = btree_insere_naocheio(parv, node->c[i], k);
    }
    return ret;
}
int btree_insere(tarv *parv, tchave k){
    tnode *raiz = parv->raiz, *b;
    int t = parv->t, ret = 1;
    if(raiz->n == 2*t-1){
        b = aloca_node(parv);
        parv->raiz = b;
        b->folha = FALSE;
        b->n = 0;
        b->c[0] = raiz;
        ret = btree_split(parv, b, 0);
        if(ret) ret = btree_insere_naocheio(parv, b, k);
    }else{
        ret = btree_insere_naocheio(parv, raiz, k);
    }
    return ret;
}
void remove_chave(tnode *node, tchave i_key){
    for(int i = i_key; i < node->n-1; ++i)
        node->chaves[i] = node->chaves[i+1];
    --node->n;
}
int procura_chave(tnode *node, tchave k){
    int ret = -1;
    for(int i = 0; i < node->n; ++i)
        if (node->chaves[i] == k)
            ret = i;
    return ret;
}
tchave predecessor(tnode *node, tchave k){
    int i_key = procura_chave(node, k);
    tnode *aux = node->c[i_key];
    while(!aux->folha)
        aux = node->c[node->n];
    return aux->chaves[aux->n - 1];
}
tchave sucessor(tnode *node, tchave k){
    int i_key = procura_chave(node, k);
    tnode *aux = node->c[i_key + 1];
    while(!aux->folha)
        aux = node->c[0];
    return aux->chaves[0];
}
int procura_ic(tnode *node, tchave k){
    int i;
    for(i = node->n-1; k < node->chaves[i] && i >= 0; --i);
        return ++i;
}
void merge(tarv *parv, tnode *node, int p){
    int i;
    tnode *x = node->c[p], *y = node->c[p + 1];
    x->chaves[x->n] = node->chaves[p];
    for(i = 0; i < y->n; i++){
        x->chaves[x->n + 1 + i] = y->chaves[i];
        if(!x->folha)
            x->c[x->n + 1 + i] = y->c[i];
    }
    if(!x->folha)
        for(i = 0; i <= y->n; i++)
            x->c[x->n + 1 + i] = y->c[i];
    x->n = 2*(parv->t)-1;
    for(i = p; i < node->n - 1; i++){
        node->chaves[i] = node->chaves[i+1];
        node->c[i+1] = node->c[i+2];
    }
    --node->n;
    if(node->n == 0){
        for(i = 0; i < x->n; i++){
            node->chaves[i] = x->chaves[i];
            node->c[i] = x->c[i];
        }
        node->c[i] = x->c[i];
        node->folha = x->folha;
        node->n = 2*(parv->t) - 1;
        free(x);
    }
    free(y);
}
int pega_irmao_maior(tnode *node, int p){
    int anterior = p -1, posterior = p +1, ret;
    if(anterior < 0)
        ret = posterior;
    else if(posterior > node->n)
        ret = anterior;
    else{
        if(node->c[anterior]->n > node->c[posterior]->n)
            ret = anterior;
        else
            ret = posterior;
    }
    return ret;
}
void pega_emprestado_irmao(tnode *node, int p, int irmao){
    int i;
    tnode *x = node->c[p],*y = node->c[p+1];
    if(p < irmao){
        x->chaves[x->n] = node->chaves[p];
        node->chaves[p] = y->chaves[0];
        x->c[x->n+1] = y->c[0];
        for(i = 0; i < y->n-1; ++i){
            y->chaves[i] = y->chaves[i+1];
            y->c[i] = y->c[i+1];
        }
        y->c[i] = y->c[i+1];
        --y->n;
        ++x->n;
    }else{
        p--;
        for(i = y->n; i > 0; --i){
            y->chaves[i] = y->chaves[i-1];
            y->c[i+1] = y->c[i];
        }
        y->chaves[0] = node->chaves[p];
        y->c[0] = x->c[x->n];
        node->chaves[p] = x->chaves[x->n-1];
        --x->n;
        ++y->n;
    }
}
int _btree_remove(tarv *parv, tnode * node, tchave k){
    int i_key = procura_chave(node,k), t = parv->t, ret = 1, i, irmao_maior;
    tnode *x,*y;
    tchave k_linha;
    if (i_key >= 0 ){
        if (node->folha)
            remove_chave(node, i_key);
        else{
            x = node->c[i_key];
            y = node->c[i_key+1];
            if (x->n >= t){
                k_linha = predecessor(node, k);
                node->chaves[i_key] = k_linha;
                ret = _btree_remove(parv, x, k_linha);
            }else if (y->n >= t){
                k_linha = sucessor(node, k);
                node->chaves[i_key] = k_linha;
                ret = _btree_remove(parv, y, k_linha);
            }else if ((x->n == t -1) && (y->n == t-1)){
                merge(parv, node, i_key);
                ret = _btree_remove(parv, node, k);
            }
        }
    }else{
        if (node->folha == TRUE)
            ret = 0;
        else{
            i = procura_ic(node, k);
            if (node->c[i]->n == t-1){
                irmao_maior = pega_irmao_maior(node, i);
                if (node->c[irmao_maior]->n >=t){
                    pega_emprestado_irmao(node, i, irmao_maior);
                    ret = _btree_remove(parv, node->c[i], k);
                }else if (node->c[irmao_maior]->n == t-1){
                    merge(parv, node, menor(i, irmao_maior)); 
                    ret = _btree_remove(parv, node, k);
                }
            }else
                ret = _btree_remove(parv, node->c[i], k);
        }
    }
    return ret;
}
int btree_remove(tarv *parv, tchave k){
    printf("Removendo a chave %d\n", k);
    return _btree_remove(parv, parv->raiz, k);
}