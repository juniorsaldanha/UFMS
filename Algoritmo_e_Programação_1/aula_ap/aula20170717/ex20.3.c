#include <stdio.h>
#include "matriz.h"

int main()
{
    int A[MAX][MAX] = { 0 };
    int tam, pot;
 
    scanf("%d", &tam);
    leiaMatriz(A, tam);
    scanf("%d", &pot);
    matrizPotenciaK(A, tam, pot);
    imprimeMatriz(A, tam);
    
    return 0;
}
