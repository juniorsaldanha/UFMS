#include <stdio.h>
int potencia(int x, int y){
	if(y == 0) return 1;
	else if(y == 1){
		return x;
	}
	else if(y % 2 == 0){
		return(x * potencia(x, y-1));
	}
	else if(y % 2 != 0){
		return(x * potencia(x, y-1));
	}
}
int main(){
	int n, i;
	scanf("%d", &n);
	int x[n], y[n], X, Y;
	for (i = 0; i < n; ++i)
	{
		scanf("%d%d", &x[i], &y[i]);
		X = x[i];
		Y = y[i];
		printf("%d\n", potencia(X, Y));
	}
	return 0;
}