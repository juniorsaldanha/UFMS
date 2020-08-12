#include <stdio.h>
#define MAX 100

int main()
{
    unsigned long long int pascal[MAX][MAX] = { 0 };
    int n, i, j;
    
    scanf("%d", &n);
    
    for (i=0; i<n; ++i)
    {
        pascal[i][0] = 1;
    }
    
    for (j=1; j<n; ++j)
    {
        for (i=1; i<n; ++i)
        {
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }
    
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (pascal[i][j] != 0)
            {
                printf("%4llu ", pascal[i][j]);
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
