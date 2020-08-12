#include <stdio.h>
#define MAX 101

int main()
{
    char palavra[MAX];
    char frase[MAX];
    int i; /* Indice da palavra */
    int j; /* Indice da frase */
    int contador = 0;
    
    scanf(" %[^\n]", frase);
    scanf(" %[^\n]", palavra);
    
    for (j = 0; frase[j] != 0; ++j) /* Para cada char da frase ... */
    {
        int indice = j;
        /* ... comparamos com cada char da palavra */
        for (i = 0; palavra[i] != 0; ++i, ++indice)
        {
            /* ao encontrar qualquer letra diferente, pare de comparar */
            if (frase[indice] != palavra[i])
            {
                break;
            }
        }
        if (palavra[i] == '\0')
        {
            ++contador;
            printf("Palavra encontrada na pos %d\n", j);
        }
    }
    printf("%d\n", contador);
    return 0;
}




