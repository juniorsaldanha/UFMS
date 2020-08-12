#include <stdio.h>

int main()
{
    int x, n;
    int potencia = 1;
    
    scanf("%d%d", &x, &n);
    while ( n > 0 )
    {
        potencia = potencia * x;
        n = n - 1;
    }
    printf("%d\n", potencia);
    
    return 0;
}
