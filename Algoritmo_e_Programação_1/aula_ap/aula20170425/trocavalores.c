#include <stdio.h>

int main()
{
    int x, y, aux;
    
    printf("Informe o primeiro valor: ");
    scanf("%d", &x);
    printf("Informe o segundo valor: ");
    scanf("%d", &y);
    if (x > y)
    {
        aux = x;
        x = y;
        y = aux;
    }
    printf("%d eh menor que %d\n", x, y);
    return 0;
}
