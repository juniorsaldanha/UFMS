#include <stdio.h>
#define MAX 100

int main()
{
    int At[MAX][MAX], m, n, i, j;
    
    scanf("%d%d", &m, &n);
    
    for (i=0; i<m; ++i)
    {
        for (j=0; j<n; ++j)
        {
            scanf("%d", &At[j][i]);
        }
    }
    
    for (i=0; i<n; ++i)
    {
        for (j=0; j<m; ++j)
        {
            printf("%2d ", At[i][j]);
        }
        
        printf("\n");
    }
    
    return 0;
}
