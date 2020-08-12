#include <stdio.h>
#define MAX 100

struct torneio
{
    int  pontos;
    char nome[MAX];
};

void ordena(struct torneio equipe[MAX], int n)
{
    int i, j;
    
    for (i=n; i>0; --i)
    {
        for (j=1; j<=i; ++j)
        {
            if (equipe[j-1].pontos < equipe[j].pontos)
            {
                struct torneio aux = equipe[j];
                equipe[j]          = equipe[j-1];
                equipe[j-1]        = aux;
            }
            else if (equipe[j-1].pontos == equipe[j].pontos)
            {
                // TODO: odenar lexicograficamente
            }
        }
    }
}

void imprime_equipe(struct torneio *equipe)
{
    printf("\tNome: %s\n\tPontos: %d\n", equipe->nome, equipe->pontos);
}

void imprime_equipes(struct torneio equipe[MAX], int n)
{
    int i;
    
    for (i=0; i<n; ++i)
    {
        printf("%d Lugar: \n", i+1);
        imprime_equipe(&equipe[i]);
    }
}

void leia_equipe(struct torneio *equipe)
{
    scanf("%d%s", &equipe->pontos, equipe->nome);
}

int main()
{
    struct torneio e[MAX];
    int n, i;
    
    scanf("%d", &n); // número de equipes
    
    for (i=0; i<n; ++i)
    {
        leia_equipe(&e[i]);
    }
    
    ordena(e, n);
    imprime_equipes(e, n);
    
    return 0;
}
