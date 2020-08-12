//Funções padrões
void trocaInt(int* a, int* b){
	int c = *a;
	*a = *b;
	*b = c;
}
void lerVetorInt(int v[], int n){
	int i;
	for(i = 0; i < n; ++i){
		scanf("%d", &v[i]);
	}
}
void imprimirVetorInt(int v[], int n){
	int i;
	for(i = 0; i < n; ++i){
		printf("%d ", v[i]);
	}
	printf("\n");
}
void lerMatrizInt(int v[9999][9999], int n, int m){
	int i, j;
	for(i = 0; i < n; ++i){
		for(j = 0; j < m; ++j){
			scanf("%d", v[i][j]);
		}
	}
}
void imprimirMatrizInt(int v[99999][99999], int n, int m){
	int i, j;
	for(i = 0; i < n; ++i){
		for(j = 0; j < m; ++j){
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
}

//Busca Binaria
int BuscaBinaria(int x, int v[], int e, int d){
    int meio= (e+d)/2;
    if(v[meio] == x) return meio;
    if(e <= d){
        if(v[meio] > x) return BuscaBinaria(x, v, e, meio-1);
        else if(v[meio] < x) return BuscaBinaria(x, v, meio+2, d);
    }
    return -1
}

//Quick Sort
int particiona(int v[], int e, int d){
	int i = e+1, j = d;
	int pivo = v[e]
	while(i <= j){
		if(v[i] <= pivo) ++i;
		else if(v[i] > pivo) --j;
		else{
			trocaInt(&v[i], &v[j]);
			++i, --j;
		}
	}
	trocaInt(&v[e], v[j]);
	return j;
}
void quicksort(int v[], int e, int d){
	int meio;
	if(e < d){
		meio = particiona(v, e, d);
		quicksort(v, e, meio-1);
		quicksort(v, meio+1, d);
	}
}

// Algoritmom de HEAP
void troca(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}
void desce(int v[], int n, int i){
	int e, d, imax;
	e = fesq(i), d = fdir(i), imax = i;
	if(e < n && v[e] > v[imax]) imax = e;
	if(d < n && v[d] > v[imax]) imax = d;
	if(imax != i){
		troca(&v[imax, &v[i]]);
		desce(v, n, imax);
	}
}
void sobe(int v[], int n, int i){
	while(v[pai(i)] < v[i]){
		troca(&v[pai(i), &v[i]]);
		i = pai(i);
	}
}
void constroeheap(int v[], int n){
	int i = pai(n-1);
	while(i >= 0){
		desce(v, n, i);
		--i;
	}
}
int pai(int i){
	int ret;
	if(i == 0) ret = 0;
	else ret=(i-1)/2;
	return ret;
}
int fesq(int i){
	
	return (2*i)+1;
}
int fdir(int i){

	return (2*i)+2;
}
// Fim das funções do algoritmo de heap.