#include <stdio.h>

int conta_digitos(int n, int d)
{
    int contador = 0;
    
    while ( n > 0 )
    {
        int resto = n % 10;
        n = n / 10;
        
        if ( resto == d )
        {
            contador++;
        }
    }
    
    return contador;
}

int main()
{
    int a, b, i;
    
    scanf("%d%d", &a, &b);
    
    for (i=1; i<=9; ++i)
    {
        if (conta_digitos(a, i) != conta_digitos(b, i))
        {
            printf("%d nao eh permutacao de %d\n", a, b);
            return 0;
        }
    }
    
    printf("%d eh permutacao de %d\n", a, b);
    return 0;
}
