#include <stdio.h>
#define MAX 5
void print_matriz(int v[MAX][MAX], int x, int y){
	int i, j;
	for (i = 0; i < x; ++i){
		for (j = 0; j < y; ++j){
			printf("%d ", v[j][i]);
		}
		printf("\n");
	}
}
void funcao(int matriz[MAX][MAX], int atual, char percorreu[], int p){
	int filho;
	if(p == 9){
		percorreu[p] = '\0';
		printf("%s\n", percorreu);
	}
	else{
		for (filho = 0; filho < MAX; ++filho){
			if(matriz[atual][filho] == 1){
				matriz[atual][filho] = -1;
				matriz[filho][atual] = -1;
				percorreu[p] = '0' + filho+1;
				funcao(matriz, filho, percorreu, p+1);
				matriz[atual][filho] = 1;
				matriz[filho][atual] = 1;

			}
		}
	}
}
int main(){
	char percorreu[10] = {"1"};
	//printf("percorreu %s\n", percorreu);
	int matriz[MAX][MAX] = {0,1,1,0,1,
							1,0,1,0,1,
							1,1,0,1,1,
							0,0,1,0,1,
							1,1,1,1,0};
	funcao(matriz, 0, percorreu, 1);
	//print_matriz(matriz, MAX, MAX);
	return 0;
}