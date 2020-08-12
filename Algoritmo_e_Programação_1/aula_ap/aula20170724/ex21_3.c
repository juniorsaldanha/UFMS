#include <stdio.h>

struct tempo
{
    int h;
    int m;
    int s;
};

int converte_segundos(struct tempo t)
{
    return (t.h * 3600) + (t.m * 60) + t.s;
}

struct tempo converte_tempo(int segundos)
{
    struct tempo t;
    
    t.h = segundos / 3600;
    t.m = (segundos % 3600) / 60;
    t.s = segundos % 60;
    
    return t;
}

struct tempo tempo_decorr(struct tempo t1, struct tempo t2)
{
    int seg_t1   = converte_segundos(t1);
    int seg_t2   = converte_segundos(t2);
    int segundos = seg_t2 - seg_t1;
    
    if (segundos < 0)
    {
        segundos += (24 * 3600);
    }
    
    return converte_tempo(segundos);
}

void print_tempo(struct tempo t)
{
    printf("%02d:%02d:%02d\n", t.h, t.m, t.s);
}

void leia_tempo(struct tempo *t)
{
    scanf("%d:%d:%d", &t->h, &t->m, &t->s);
}

int main()
{
    struct tempo t[2];
    
    leia_tempo(&t[0]);
    leia_tempo(&t[1]);
    
    print_tempo(tempo_decorr(t[0], t[1]));
    
    return 0;
}
