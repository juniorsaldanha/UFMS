#include <stdio.h>

void funcao_por_copia(int x, int y)
{
    printf("funcao_por_copia:\n");
    printf("\tx = %d\n", x);
    printf("\ty = %d\n", y);
    x = x * 2; y = y * 2;
    printf("\tx = %d\n", x);
    printf("\ty = %d\n", y);
}

void funcao_por_referencia(int *x, int *y)
{
    printf("funcao_por_referencia:\n");
    printf("\t*x = %d\n", *x);
    printf("\t*y = %d\n", *y);
    *x = *x * 2; *y = *y * 2;
    printf("\t*x = %d\n", *x);
    printf("\t*y = %d\n", *y);
}

int main()
{
    int a = 10, b = 20;
    printf("a = %d\nb = %d\n", a, b);
    funcao_por_copia(a, b);
    printf("a = %d\nb = %d\n", a, b);
    funcao_por_referencia(&a, &b);
    printf("a = %d\nb = %d\n", a, b);
    return 0;
}
