#include <stdio.h>
int main(){
	int v[5][3] = {{10,20,30},{40,50,60},{70,80,90},{100,110,120},{130,140,150}};
	int *p;
	printf("v 		%p\n", v);
	printf("v 		%d\n", **v);
	printf("v+1		%p\n", v+1);
	printf("v+1		%d\n", **(v+1));
	printf("v+1	sem	%d\n", **v+1);
	printf("v+2		%p\n", v+2);
	printf("v+2		%d\n", **(v+2));
	printf("v+2	sem	%d\n", **v+2);
	printf("\n");
	p = *v;
	printf("p 		%p\n", p);
	printf("p 		%d\n", *(p));
	printf("p+1		%p\n", p+1);
	printf("p+1		%d\n", *(p+1));
	printf("p+2		%p\n", p+2);
	printf("p+2		%d\n", *(p+2));
	return 0;
}