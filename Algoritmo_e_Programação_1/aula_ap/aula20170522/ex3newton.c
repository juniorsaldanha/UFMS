#include <stdio.h>

int main()
{
    double x, yant, yatual=1.0, epsilon;
    int contador=0;
    
    scanf("%lf%lf", &x, &epsilon);
    
    yatual = x/2.0; /* chute */
    
    do
    {
        yant   = yatual;
        yatual = (yatual + x/yatual) / 2.0;
        ++contador;
    }
    while ( (yant - yatual) > epsilon );
    
    printf("%.10lf %d\n", yatual, contador);
    
    return 0;
}
