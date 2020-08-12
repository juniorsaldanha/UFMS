#include <stdio.h>

int main()
{
    int i;
    char digito;
    
    for (i=0; i<7; ++i)
    {
        scanf("%c", &digito);
        
        if ( digito >= '0' && digito <= '9' )
        {
            printf("%c", digito);
        }
        else
        {
            if ( digito >= 'A' && digito <= 'C' )
            {
                printf("2");
            }
        }
    }
}
