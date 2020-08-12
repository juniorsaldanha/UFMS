#include <stdio.h>
#define NUMFACES 6

int main()
{
    int contadorfaces[NUMFACES] = { 0 };
    int numlancamentos, i;
    
    scanf("%d", &numlancamentos);
    
    for (i=0; i<numlancamentos; ++i)
    {
        int face;
        
        scanf("%d", &face);
        
        ++(contadorfaces[face - 1]);
    }
    for (i=0; i<NUMFACES; ++i)
    {
        printf("Face %d = %d\n", i+1, contadorfaces[i]);
    }
    
    return 0;
}
