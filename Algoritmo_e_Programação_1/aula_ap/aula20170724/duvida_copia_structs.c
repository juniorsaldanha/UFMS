#include <stdio.h>
#define MAX 5

struct Registro
{
    int valor;
    int vetor[MAX];
};

void printVetor(int v[], int n)
{
    int i;
    for (i=0; i<n; ++i)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void printRegistro(struct Registro *r)
{
    printf("Valor = %d\n", r->valor );
    printVetor(r->vetor, MAX);
}

int main()
{
    struct Registro r1 = {1, {0, 2, 4, 6, 8}};
    struct Registro r2 = {2, {10, 12, 14, 16, 18}};
    
    printRegistro(&r1);
    printRegistro(&r2);
    
    r1 = r2;
    
    printRegistro(&r1);
    printRegistro(&r2);
    
    return 0;
}
