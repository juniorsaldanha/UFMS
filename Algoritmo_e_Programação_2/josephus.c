#include <stdio.h>
int funcao(int n, int k){
	if(n==1) return 1;
	return (((funcao(n - 1, k) + k - 1) %n)+1);
}
int main(){
	int n, k, i;
	scanf("%d", &i);
	while(--i){
		scanf("%d %d", &n, &k);
		printf("%d\n", funcao(n, k));
	}
	return 0;
}