#include <stdio.h>

int main()
{
    int i;
    int n;
    
    scanf("%d", &n);
    printf("%d\n", n);

    for(i=n-1; i>=0; --i)
    {
        printf("%d ", i);
    }

    printf("\n");
    
    return 0;
}
