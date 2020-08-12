#include <stdio.h>

int main()
{
    struct
    {
        int a;
        int b;
        int c;
    }
    s;
    
    int* pi = &s.a;
    
    scanf("%d %d %d", &s.a, &s.b, &s.c);
    
    printf("%d %d %d\n", s.a, s.b, s.c);
    
    scanf("%d %d %d", pi, &s.b, &s.c);
    
    printf("%d %d %d\n", s.a, s.b, s.c);
    
    printf("&s.a = %p    s.a = %d \n", (void*)&s.a, s.a);
    printf("&s.b = %p    s.b = %d \n", (void*)&s.b, s.b);
    printf("&s.c = %p    s.c = %d \n", (void*)&s.c, s.c);
    printf("pi   = %p\n", (void*)pi);
    printf("&pi  = %p\n", (void*)&pi);
    
    return 0;
}
