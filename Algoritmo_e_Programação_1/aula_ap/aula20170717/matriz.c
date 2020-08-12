#include <stdio.h>
#include "matriz.h"

void leiaMatriz(int A[MAX][MAX], int n)
{
    int i, j;
    
    for (i=0; i<n; ++i)
    {
        for (j=0; j<n; ++j)
        {
            scanf("%d", &A[i][j]);
        }
    }
}

void imprimeMatriz(int A[MAX][MAX], int n)
{
    int i, j;
    
    for (i=0; i<n; ++i)
    {
        for (j=0; j<n; ++j)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void identidade(int I[MAX][MAX], int n)
{
    int i, j;
    
    for (i=0; i<n; ++i)
    {
        for (j=0; j<n; ++j)
        {
            // se (i == j) a expr. retorna TRUE, ou seja, 1
            // caso contrario, a expr. retorna FALSE, ou seja, 0
            I[i][j] = (i == j);
        }
    }
}

void multimat(int C[MAX][MAX], int A[MAX][MAX], int B[MAX][MAX], int n)
{
    int i, j, k;
    
    for (i=0; i<n; ++i)
    {
        for (j=0; j<n; ++j)
        {
            C[i][j] = 0;
            
            for (k=0; k<n; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void copia(int A[MAX][MAX], int B[MAX][MAX], int n)
{
    int i, j;
    
    for (i=0; i<n; ++i)
    {
        for (j=0; j<n; ++j)
        {
            A[i][j] = B[i][j];
        }
    }
}

void matrizPotenciaK(int A[MAX][MAX], int n, int k)
{
    int FATOR[MAX][MAX] = { 0 };
    int CA[MAX][MAX] = { 0 };
    
    if ( k == 0 )
    {
        identidade(A, n);
        return;
    }
    
    copia(FATOR, A, n);
    copia(CA, A, n);
    
    while ( k > 1 )
    {
        multimat(A, FATOR, CA, n);
        copia(CA, A, n);
        --k;
    }
}
