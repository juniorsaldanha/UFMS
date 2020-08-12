#include <stdio.h>

int main()
{
    int n, k;
    double h;
    
    scanf("%d", &n);
    h = 0.0;
    
    for(k=1; k<=n; ++k)
    {
        h = h + 1.0/k;
    }
    printf("%lf\n", h);
    return 0;
}
