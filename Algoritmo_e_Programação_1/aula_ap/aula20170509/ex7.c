#include <stdio.h>

int main()
{
    int n, cont = 1, anterior, atual;
    scanf("%d", &n);
    scanf("%d", &anterior);
    n = n - 1;
    
    while (n > 0)
    {
        scanf("%d", &atual);
        n = n - 1;
        
        if (atual != anterior)
        {
            cont = cont + 1;
        }
        anterior = atual;
    }
    printf("%d\n", cont);
    return 0;
}
