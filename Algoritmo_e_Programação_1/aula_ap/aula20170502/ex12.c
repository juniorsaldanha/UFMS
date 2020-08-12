#include <stdio.h>

int main()
{
    int x, n;
    int pares = 0;
    int impares = 0;
    
    scanf("%d", &n);
    
    while ( n > 0 )
    {
        scanf("%d", x);
        
        if ( x % 2 == 0 )
        {
            pares = pares + 1;
        }
        else
        {
            impares = impares + 1;
        }
        n = n - 1;
    }
    
    printf("%d\n", pares);
    printf("%d\n", impares);
    
    return 0;
}
