#include <stdio.h>
#define MAX 100

int main()
{
    int M[MAX][MAX], v[MAX], R[MAX] = { 0 };
    int m, n, i, j;
    
    scanf("%d%d", &m, &n);
    
    for (i=0; i<m; ++i)
    {
        for (j=0; j<n; ++j)
        {
            scanf("%d", &M[i][j]);
        }
    }
    
    for (i=0; i<n; ++i)
    {
        scanf("%d", &v[i]);
    }
    
    for (i=0; i<m; ++i)
    {
        for (j=0; j<n; ++j)
        {
            R[i] += M[i][j] * v[j];
        }
    }
    
    for (i=0; i<m; ++i)
    {
        printf("%02d\n", R[i]);
    }
    
    printf("\n");
    
    return 0;
}
