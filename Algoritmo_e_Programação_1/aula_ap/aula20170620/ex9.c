#include <stdio.h>
#define MAX 101

int main()
{
    char numero1[MAX] = {0}, numero2[MAX] = {0}, resultado[MAX] = {0};
    int i; // tamanho da string
    int j;
    
    scanf("%s", numero1);
    scanf("%s", numero2);
    
    // Descobre o tamanho da string numero1
    for (i=0; numero1[i] != '\0'; ++i) {}
    
    // Inverte string do numero1
    for (j=0, i=i-1; j <= i; ++j, --i)
    {
        char aux   = numero1[j];
        numero1[j] = numero1[i];
        numero1[i] = aux;
    }
    
    // Descobre o tamanho da string numero2
    for (i=0; numero2[i] != '\0'; ++i) {}
    
    // Inverte string do numero2
    for (j=0, i=i-1; j <= i; ++j, --i)
    {
        char aux   = numero2[j];
        numero2[j] = numero2[i];
        numero2[i] = aux;
    }
    
    // Conversão do código ASCII para valor inteiro
    for (i=0; numero1[i] != '\0'; ++i)
    {
        numero1[i] -= 48;
    }
    
    // Conversão do código ASCII para valor inteiro
    for (i=0; numero2[i] != '\0'; ++i)
    {
        numero2[i] -= 48;
    }
    
    // Soma dos dois vetores seguindo regra de soma matematica
    for (i=0; numero1[i] != '\0'; ++i)
    {
        resultado[i]   = ( numero1[i] + numero2[i] + resultado[i] ) % 10;
        
        // Conversão do valor inteiro para código ASCII
        resultado[i]  += 48;
        
        resultado[i+1] = ( numero1[i] + numero2[i] ) / 10; // vai um
    }
    
    // Conversão do valor inteiro para código ASCII
    if ( resultado[i] != 0 )
    {
        resultado[i]  += 48;
    }
    
    // Descobre o tamanho da string resultado
    for (i=0; resultado[i] != '\0'; ++i) {}
    
    // Inverte string do resultado
    for (j=0, i=i-1; j <= i; ++j, --i)
    {
        char aux   = resultado[j];
        resultado[j] = resultado[i];
        resultado[i] = aux;
    }
    
    printf("%s\n", resultado);
    
    return 0;
}
