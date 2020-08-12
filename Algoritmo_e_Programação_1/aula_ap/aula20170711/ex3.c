#include <stdio.h>

void quebra(int n, int *primeiro, int *ultimo, int *miolo)
{
    int pot10 = 1, numero = n;
    
    *ultimo = numero % 10;
    numero  = numero / 10;
    *miolo  = 0;
    
    while ( numero > 9 )
    {
        *miolo = *miolo + (numero % 10) * pot10;
        pot10  = pot10 * 10;
        numero = numero / 10;
    }
    
    if ( n < 10 )
    {
        *primeiro = n;
    }
    else
    {
        *primeiro = numero;
    }
}

int main()
{
    int numero, p, u, m;
    scanf("%d", &numero);
    
    quebra(numero, &p, &u, &m);
    
    while ( (p == u) && (m > 0) )
    {
        quebra(m, &p, &u, &m);
    }
    
    if ((p == u) && (m == 0))
    {
        printf("PALINDROMO\n");
    }
    else
    {
        printf("NAO PALINDROMO\n");
    }
        
    return 0;
}
