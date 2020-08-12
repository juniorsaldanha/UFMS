#include <stdio.h>

int main()
{
    int x, n, aux;
    
    scanf("%d", &n);
    scanf("%d", &aux);
    n = n - 1; /* ja li o primeiro elemento em aux */
    
    while ( n > 0 )
    {
        scanf("%d", &x);
        if ( x >= aux )
        {
            aux = x;
        }
        else
        {
            printf("A sequencia nao eh crescente.\n");
            n = 0;
        }
        n = n - 1;
    }
    if ( n != -1 )
    {
        printf("A sequencia eh crescente.\n");
    }
    return 0;
}
