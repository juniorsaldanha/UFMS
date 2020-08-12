#include <stdio.h>
int ler_vetor(int A[], int n, int *Amigo, int *Voce, char who){
	int i;

	for(i = 0; i < n; ++i){
		scanf("%d", &A[i]);
		if(who == 'A'){
			*Amigo += A[i];
			who = 'V';
		} 
		else{
			*Voce += A[i];
			who = 'A';
		}
	}
	return 0;
}

int main(){
	char who;
	int n, V = 0, A = 0;
	scanf("%c", &who);
	scanf("%d", &n);
	int notas[n];
	ler_vetor(notas, n, &A, &V, who);
	printf("VOCE: %d AMIGO: %d\n", V, A);
	return 0;
}