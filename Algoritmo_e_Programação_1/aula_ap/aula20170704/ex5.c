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

int main()
{
    int n, x, y, cont = 0;
    
    // Numero de duplas de inteiros
    scanf("%d", &n);
    
    for ( ; n > 0; --n)
    {
        scanf("%d%d", &x, &y);
        
        if ( mdc(x, y) == 1 )
        {
            ++cont;
        }
    }
    
    printf("%d\n", cont);
    
    return 0;
}
