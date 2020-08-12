#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define MAX 10


void build_prefix_table(char *p, int *prefix_table){
    int i;
    int j;
    int m;
    m = strlen(p);
    j = -1;
    i = 0;
    prefix_table[0] = -1;
    for(i=1; i < m;i++){
        while(j > -1 && p[j+1] != p[i])
            j = prefix_table[j];
        if (p[j+1] == p[i])
            j++;
        prefix_table[i] = j;
    }
    for (i=0;i<m;i++){
        printf("%2d ",i);
    }
    printf("\n");
    for (i=0;i<m;i++){
        printf("%2c ",p[i]);
    }
    printf("\n");
    for (i=0;i<m;i++){
        printf("%2d ",prefix_table[i]);
    }
    printf("\n");

}

void kmp(char *p, char *t){
    int n;
    int m;
    int *prefix_table;
    int i,j;
    n = strlen(t);
    m = strlen(p);
    prefix_table = (int *)malloc(sizeof(int)*m);
    build_prefix_table(p,prefix_table);
    j = 0;
    for(i=1; i < n;i++){
        while(j > -1 && p[j+1] != t[i])
            j = prefix_table[j];
        if (p[j+1] == t[i])
            j++;
        if (j == (m-1)){
            printf("Match at %d\n",i-(m-1));
            j = prefix_table[j];
        }
    }
}


void test_kmp(){
    char *pattern;
    char *text;

    pattern = "abcabc";
    text    = "abcabcabcdababcabc";
    kmp(pattern,text);
}

void test_build_prefix(){
    int  table[MAX];
    char *x;
    int m,i;

    x = "abcabcx";
    
    build_prefix_table(x,table);
    m = strlen(x);
    for (i=0;i<m;i++)
        printf("%d ",table[i]);

    printf("\n");


}


int main(void){
    test_build_prefix();
    test_kmp();
    return 0;
}