#include <stdio.h>

int main()
{
    struct
    {
        int h, m, s;
    }
    inicial, final, diferenca;
    
    int totali, totalf;
    
    scanf("%d:%d:%d", &inicial.h, &inicial.m, &inicial.s);
    scanf("%d:%d:%d", &final.h, &final.m, &final.s);
    
    totali = inicial.s + inicial.m*60 + inicial.h*3600;
    totalf = final.s + final.m*60 + final.h*3600;
    
    diferenca.s = totalf - totali;
    diferenca.h = diferenca.s / 3600;
    diferenca.m = (diferenca.s % 3600) / 60;
    diferenca.s = (diferenca.s % 3600) % 60;
    
    printf("%02d:%02d:%02d\n", diferenca.h, diferenca.m, diferenca.s);
    
    return 0;
}
