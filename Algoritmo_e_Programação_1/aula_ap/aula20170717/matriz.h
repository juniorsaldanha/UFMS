// ---
// INCLUDE GUARD
// ---
#ifndef __MATRIZ_H
#define __MATRIZ_H

#define MAX 100

void leiaMatriz(int A[MAX][MAX], int n);

void imprimeMatriz(int A[MAX][MAX], int n);

void identidade(int I[MAX][MAX], int n);

void multimat(int C[MAX][MAX], int A[MAX][MAX], int B[MAX][MAX], int n);

void copia(int A[MAX][MAX], int B[MAX][MAX], int n);

void matrizPotenciaK(int A[MAX][MAX], int n, int k);

#endif
