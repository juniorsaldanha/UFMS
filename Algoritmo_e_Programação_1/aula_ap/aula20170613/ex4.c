#include <stdio.h>
#define MAX 100

int main()
{
    int m[MAX][MAX];
    int n, i, j;
    int valorSoma=0, somaAux;
    
    scanf("%d", &n);
    
    for (i=0; i<n; ++i)
    {
        for (j=0; j<n; ++j)
        {
            scanf("%d", &m[i][j]);
        }
    }
    
    for (i=0; i<n; ++i)
    {
        /* Soma dos valores da linha 0 */
        valorSoma += m[0][i];
    }
    
    /* Começamos pela linha 1 */
    for (i=1; i<n; ++i)
    {
        /* Zera somaAux no começo de cada linha */
        somaAux = 0;
        
        /* Soma dos valores da linha i */
        for (j=0; j<n; ++j)
        {
            somaAux += m[i][j];
        }
        
        if (somaAux != valorSoma)
        {
            printf("Nao eh quadrado magico\n");
            return 0;
        }
    }
    
    /* Começamos pela coluna 0 */
    for (i=0; i<n; ++i)
    {
        /* Zera somaAux no começo de cada coluna */
        somaAux = 0;
        
        /* Soma os valores da coluna i */
        for (j=0; j<n; ++j)
        {
            somaAux += m[j][i];
        }
        
        if (somaAux != valorSoma)
        {
            printf("Nao eh quadrado magico\n");
            return 0;
        }
    }
    
    somaAux=0;
    
    /* Diagonal principal */
    for (i=0; i<n; ++i)
    {
        somaAux += m[i][i];
    }
    
    if (somaAux != valorSoma)
    {
        printf("Nao eh quadrado magico\n");
        return 0;
    }
    
    somaAux=0;

    /* Diagonal secundaria */    
    for (i=0; i<n; ++i)
    {
        somaAux += m[i][(n-1)-i];
    }
    
    if (somaAux != valorSoma)
    {
        printf("Nao eh quadrado magico\n");
        return 0;
    }
    
    /* Verificar valores unicos */
    for (i=0; i<n; ++i)
    {
        for (j=0; j<n; ++j)
        {
            int elementoFixo = m[i][j];
            int k, l;
            
            for (k=0; k<n; ++k)
            {
                for (l=0; l<n; ++l)
                {
                    /* Comparo elemento fixo (i,j) com todos os elementos
                     * de coordenadas (k,l) diferentes de (i,j) 
                     */
                    if ( (elementoFixo == m[k][l]) && (i != k && j != l) )
                    {
                        printf("Nao eh quadrado magico\n");
                        return 0;
                    }
                }
            }
        }
    }
    
    printf("Eh quadrado magico\n");
    
    return 0;
}
