#include <stdio.h>
#define MAX 50

int main()
{
    char cacapalavras[MAX][MAX];
    int  m, n, k, i, j, p;
    
    scanf("%d%d", &m, &n);
    
    for (i=0; i<m; ++i)
    {
        for (j=0; j<n; ++j)
        {
            scanf("%c", &cacapalavras[i][j]);
        }
    }
    
    scanf("%d", &k);
    
    char palavra[k][MAX+1];
    
    for (i=0; i<m; ++i) // Linhas do cacapalavras
    {
        for (j=0; j<n; ++j) // Colunas do cacapalavras
        {
            for (p=0; p<k; ++p) // Palavra do vetor de palavras
            {
                
            }
        }
    }
    
    return 0;
}
