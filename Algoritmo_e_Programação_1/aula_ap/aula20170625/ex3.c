#include <stdio.h>
#define MAX 100

int main()
{
    int estrada[MAX][MAX] = { 0 }, n, i, j;
    
    scanf("%d", &n); // Quantidade de cidades
    
    for (i=0; i<n; ++i)
    {
        for (j=0; j<n; ++j)
        {
            scanf("%d", &estrada[i][j]);
        }
    }

    // Letra A)
    {
        int cidade, contador = -1;
        
        scanf("%d", &cidade); // Cidade a ser checada
        
        for (i=0; i<n; ++i)
        {
            contador += estrada[i][cidade]; // Acesso todas as linhas
        }
        
        printf("a)\n");
        
        printf("    Estradas que chegam a cidade %d = %d\n", cidade, contador);
        contador = -1;
        
        for (i=0; i<n; ++i)
        {
            contador += estrada[cidade][i]; // Acesso todas as colunas
        }
        
        printf("    Estradas que saem da cidade %d = %d\n", cidade, contador);
    }
    
    // Letra B)
    {
        struct
        {
            int numero;
            int quantidade;
        }
        cidadeMaisEstradas = { 0, -1 };
        
        int contador = -1;
        
        for (i=0; i<n; ++i) // Colunas
        {
            contador = -1;
            
            for (j=0; j<n; ++j) // Linhas
            {
                // Conta quantas estradas chegam à cidade i
                contador += estrada[j][i]; 
            }
            
            if ( contador > cidadeMaisEstradas.quantidade )
            {
                cidadeMaisEstradas.numero     = i;
                cidadeMaisEstradas.quantidade = contador;
            }
        }
        
        printf("b)\n");
        printf("    A cidade %d tem maior numero de estradas que chegam = %d\n", cidadeMaisEstradas.numero, cidadeMaisEstradas.quantidade);
    }
    
    // Letra C)
    {
        int cidade;
        
        scanf("%d", &cidade);
        printf("c)\n");
        
        for (i=0; i<n; ++i)
        {
            if ( estrada[cidade][i] != 1 || estrada[i][cidade] != 1 )
            {
                printf("    A cidade %d NAO tem ida e volta para todas a cidades.\n", cidade);
                break;
            }
        }
        
        // Se o laço terminou sem ser via BREAK, então a cidade é conectada a todas as outras com ida e volta
        if ( i == n )
        {
            printf("    A cidade %d TEM ida e volta para todas a cidades.\n", cidade);
        }
    }
    
    // Letra D)
    {
        int cidade;
        scanf("%d", &cidade);
        printf("d)\n");
        
        for (i=0; i<n; ++i)
        {
            if ( estrada[i][cidade] == 1 )
            {
                printf("    A cidade %d chega em %d\n", i, cidade);
            }
        }
    }
    
    return 0;
}
