#include <stdio.h>
#include <stdlib.h>

void troca (int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main()
{
    int n, /*v[100]*/ *v, i, m;
    
    scanf("%d", &n);
    
    v = malloc(sizeof(int)*n);
    
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &v[i]);
    }
    
    for (m = n; m > 0; --m)
    {
        for (i = 1; i< m; ++i)
        {
            if ( v[i-1] > v[i])
            {
                troca(&v[i-1], &v[i]);
            }
        }
    }
    
    for (i=0; i<n; ++i)
    {
        printf("%d ", v[i]);
    }
    
    printf("\n");
    
    free(v);
    
    return 0;
}
