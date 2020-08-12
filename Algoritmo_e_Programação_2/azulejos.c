#include <stdio.h>

int fib(int n){
	if(n==1)return 1;
	if(n==2)return 2;
	return fib(n-2)+fib(n-1);
}
int main(){
	int k,n;
	scanf("%d",&k);
	while(k-- > 0){
		scanf("%d",&n);
		printf("%d\n",fib(n));
	}
}