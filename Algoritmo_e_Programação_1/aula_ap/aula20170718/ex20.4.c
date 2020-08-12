#include <stdio.h>
#define MAX 100

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

void imprimaMatriz(int A[MAX][MAX], int n)
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

int linha(int A[MAX][MAX], int n, int i)
{
    int presente[n];
    int j;
    
    for (j=0; j<n; ++j)
    {
        if (A[i][j] <= n)
        {
            int elemento = (A[i][j] - 1);
            presente[elemento] = 1;
        }
        else
        {
            return 0;
        }
    }
    for (j=0; j<n; ++j)
    {
        if ( presente[j] == 0 )
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int tam;
    int M[MAX][MAX] = { 0 };
    int i;
    
    scanf("%d", &tam);
    leiaMatriz(M, tam);
    for (i=0; i<tam; ++i)
    {
        if ( linha(M, tam, i) == 0 || coluna(M, tam, i) == 0 )
        {
            printf("NAO EH QUADRADO LATINO\n");
            return 0;
        }
    }
    
    printf("EH QUADRADO LATINO\n");
    return 0;
}
