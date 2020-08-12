#include <stdio.h>

int main()
{
    int fibant = 0, fibatual = 1, n, i;
    
    scanf("%d", &n);
    printf("%d", fibant); /* sempre imprime o primeiro pois n >= 1 */
    
    for (i=1; i<n; ++i)
    {
        int temp;
        printf(",%d", fibatual);
        
        temp     = fibant + fibatual;
        fibant   = fibatual;
        fibatual = temp;
    }
    
    printf("\n");
    
    return 0;
}
