#include <stdio.h>

int main()
{
    int idade;
    
    printf("Informe sua idade: ");
    scanf("%d", &idade);
    
    if (idade < 30)
    {
        printf("Idade eh menor que 30.\n");
        
        if (idade > 20)
        {
            printf("Nossa, voce eh bem jovem!\n");
        }
    }
    else
    {
        printf("Nossa, vc eh bem velinho!\n");
    }
    
    printf("Ate logo!\n");
    
    return 0;
}
