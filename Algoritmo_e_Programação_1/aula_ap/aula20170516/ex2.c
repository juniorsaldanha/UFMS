#include <stdio.h>

int main()
{
    int mes;
    double capital, juros;
    
    scanf("%lf", &capital);
    scanf("%lf", &juros);
    
    for (mes=1; mes<=12; ++mes)
    {
        capital = juros/100 * capital + capital;
        
        printf("mes %d: %lf\n", mes, capital);
    }
    
    return 0;
}
