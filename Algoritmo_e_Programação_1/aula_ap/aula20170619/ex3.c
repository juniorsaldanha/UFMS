#include <stdio.h>

int main()
{
    struct
    {
        int d, m, a;
    }
    inicial, final;
    
    int f;
    int g;
    int ninicial, nfinal;
    
    scanf("%d/%d/%d", &final.d, &final.m, &final.a);
    scanf("%d/%d/%d", &inicial.d, &inicial.m, &inicial.a);
    
    if (final.m <= 2)
    {
        f = final.a - 1;
        g = final.m + 13;
    }
    else
    {
        f = final.a;
        g = final.m + 1;
    }
    
    nfinal = ((1461 * f) / 4) + ( (153 * g) / 5 ) + final.d;
    
    if (inicial.m <= 2)
    {
        f = inicial.a - 1;
        g = inicial.m + 13;
    }
    else
    {
        f = inicial.a;
        g = inicial.m + 1;
    }
    
    ninicial = ((1461 * f) / 4) + ( (153 * g) / 5 ) + inicial.d;
    
    printf("%d\n", nfinal - ninicial);
    
    return 0;
}
