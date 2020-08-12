#include <stdio.h>
#define NUMQUESTOES 20

int main()
{
    char gabarito[NUMQUESTOES];
    int i, numalunos;
    
    for (i=0; i<NUMQUESTOES; ++i)
    {
        scanf(" %c", &gabarito[i]);
    }

    scanf("%d", &numalunos);
    
    for (i=0; i<numalunos; ++i) // Para cada aluno...
    {
        int j, respostascorretas = 0;
        
        for (j=0; j<NUMQUESTOES; ++j) // ... leio cada resposta ...
        {
            char resposta;
            scanf(" %c", &resposta);
            
            if (resposta == gabarito[j]) // ... verifico a corretude!
            {
                ++respostascorretas;
            }
        }
        printf("Respostas corretas = %d\n", respostascorretas);
    }
    return 0;
}
