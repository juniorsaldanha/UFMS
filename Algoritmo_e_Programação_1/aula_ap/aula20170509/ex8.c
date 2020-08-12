#include <stdio.h>

int main()
{
    int n, compatual, compmax, atual, anterior;
    
    compatual = 1;
    compmax   = 1;
    scanf("%d", &n);
    scanf("%d", &anterior);
    n = n - 1;
    while (n > 0)
    {
        scanf("%d", &atual);
        n = n - 1;
        if ( atual >= anterior )
        {
            compatual = compatual + 1;
        }
        else
        {
            compatual = 1;
        }
        if ( compatual > compmax )
        {
            compmax = compatual;
        }
        anterior = atual;
    }
    printf("%d", compmax);
    return 0;
}
