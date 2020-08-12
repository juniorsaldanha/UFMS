#include <stdio.h>
int mult(int a, int b){
	return (a*b);
}
int soma(int a, int b){
	return (a+b);
}
int subt(int a, int b){
	return (a-b);
}
int main(){
	int n, a, b, result = 0;
	char operacao[1];
	scanf("%d", &n);
	scanf("%d", &a);
	int (*pfunc)(int a, int b);
	while(n--){
		scanf("%s", &operacao[0]);
		if(operacao[0] == '*'){
			pfunc = &mult;
			scanf("%d", &b);
		}
		else if(operacao[0] == '+'){
			pfunc = &soma;
			scanf("%d", &b);
		}
		else if(operacao[0] == '-'){
			pfunc = &subt;
			scanf("%d", &b);
		}
		if(operacao[0] != 'c'){
			result += pfunc(a, b);
			a = result;
			printf("%d\n", result);
			result = 0;
		}
		else if(operacao[0] == 'c'){
			printf("apagado\n");
			result = 0, a = 0, b = 0;
			scanf("%d", &a);
		}
	}
	return 0;
}