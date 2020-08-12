#include <stdio.h>

int main()
{
    int n, x, acumulador = 0;
    
    scanf("%d", &n);
    
    while ( n > 0 )
    {
        scanf("%d", &x);
        if ( x > 0 )
        {
            acumulador = acumulador + x;
        }
        n = n - 1;
    }
    
    printf("%d\n", acumulador);
    return 0;
}
