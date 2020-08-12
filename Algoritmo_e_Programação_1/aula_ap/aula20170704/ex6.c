#include <stdio.h>

int mdc(int a, int b)
{
    int aux;
    
    while (b > 0)
    {
        aux = a % b;
        a = b;
        b = aux;
    }
    
    return a;
}

int verifica_primo(int p)
{
    int i;
    
    for (i=1; i<p; ++i)
    {
        if ( mdc(p, i) != 1 )
        {
            return 0; // Falso, nao eh primo
        }
    }
    
    if ( mdc(p, i) != p )
    {
        return 0; // Falso, nao eh primo
    }
    
    return 1; // Verdadeiro, eh primo
}

int main()
{
    int n, soma = 0;
    
    scanf("%d", &n);
    
    while (n > 0)
    {
        int x;
        
        scanf("%d", &x);
        
        if ( verifica_primo(x) == 1 )
        {
            soma += x;
        }
        
        --n;
    }
    
    printf("%d\n", soma);
    
    return 0;
}
