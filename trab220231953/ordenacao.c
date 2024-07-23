#include "ordenacao.h"
#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Aurelio Gabriel Ortiz Vieira", MAX_CHAR);
    // adicionada terminação manual para caso de overflow
    nome[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20231953; }

void copiar(int v[], int64_t a, int64_t b, int aux[]){
	int64_t i, j;
	
	j = 0;
	for(i = a; i < b; i++){
		v[i] = aux[j];
		j++;
	}
}

void merge(int v[], int64_t a, int64_t m, 
				int64_t b, uint64_t *comp) {
	int64_t p1, p2;
	int64_t i, j;

	int *aux = (int*)malloc( (b+1) * sizeof(int) );
    if (aux == NULL) {
        printf("Falha fatal. Impossível alocar memoria.\n");
        return;
    }
	
	if(a >= b){
		return;
	}
	
	p1 = a;	
	p2 = m+1;		
	i = 0;	
	
	while( (i <= b) && (p1 <= b) ){
		(*comp)++;
		if( (p2 > b) || (p1 <= m && v[p1] <= v[p2]) ) {
			j = p1;
			p1++;
		}else{
			j = p2;
			p2++;
		}
		aux[i] = v[j];
		i++;
	}
	copiar(v, a, b+1, aux);

	free(aux);
}

void merge_sort(int v[], int64_t a, int64_t b,
					uint64_t *comp){
	int64_t m;
	
	if(a >= b){
		return;
	}

	m = (a+b) / 2;
	merge_sort(v, a, m, comp);
	merge_sort(v, m+1, b, comp);
	
	merge(v, a, m, b, comp);
}

uint64_t mergeSort(int vetor[], size_t tam) {
	uint64_t numComp;

	numComp = 0;
	merge_sort(vetor, 0, tam-1, &numComp);
	
	return numComp;
}

void trocar(int v[], int64_t a, int64_t b){
	int aux;
	
	aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}

int64_t particionar(int v[], int64_t a, int64_t b, uint64_t *comp){
	int x;
	int64_t m;
	
	x = v[b]; //pivô
	m = a;

	for(int i = a; i <= b-1; i++){
		(*comp)++;
		if( v[i] <= x ){
			trocar(v, m, i);
			m++;
		}	
	}
	trocar(v, m, b);
	
	return m;
}

void quick_sort(int v[], int64_t a, int64_t b, uint64_t *comp){
	int64_t m;
	
	if(a >= b){
		return;
	}
	m = particionar(v, a, b, comp);
	quick_sort(v, a, m-1, comp);
	quick_sort(v, m+1, b, comp);
}

uint64_t quickSort(int vetor[], size_t tam) {
	uint64_t numComp;

	numComp = 0;
	quick_sort(vetor, 0, tam-1, &numComp);
	
	return numComp;
}

int64_t esquerda(int64_t i){
	return 2*i;
}

int64_t direita(int64_t i){
	return (2*i)+1;
}

void max_heapify(int v[], int64_t ind, int64_t n, 
						uint64_t *comp) {
	int64_t l, r;
	int64_t maior;
	
	l = esquerda(ind);
	r = direita(ind);
	(*comp)++;
	if( ( l <= n) && (v[l] > v[ind]) ){
		maior = l;
	}else {
		maior = ind;
	}

	if( (r <= n) && (v[r] > v[maior]) ) {
		maior = r;
	}
	
	if(maior != ind) {
		trocar(v, ind, maior);
		max_heapify(v, maior, n, comp);
	}

}

void construir_max_heap(int v[], int64_t n, uint64_t *numComp){

	for(int64_t i = n/2; i >= 0; i--) {
		max_heapify(v, i, n, numComp);
	}
}

void heap_sort(int v[], int64_t n, uint64_t *numComp){
	
	construir_max_heap(v, n, numComp);
	
	for(uint64_t j = n; j >= 1; j--){
		trocar(v, 0, j);
		max_heapify(v, 0, j-1, numComp);
	}
}

uint64_t heapSort(int vetor[], size_t tam) {
    uint64_t numComp;
    
    numComp = 0;
	heap_sort(vetor, tam-1, &numComp);

    return numComp;
}

uint64_t mergeSortSR(int vetor[], size_t tam) {
	uint64_t numComp;

	numComp = -1;
	vetor[tam-1] = 10;
	printf("Não consegui fazer\n");
	
	return numComp;
}


void quick_sortSR(int v[], int64_t a, int64_t b, uint64_t *comp) {
	struct pilha *p;
	int64_t m;
	
	p = pilha_cria();
	if(!p){
		printf("\nErro ao criar pilha\n");	
		return;
	}
	push(p, a);
	push(p, b);
	while( !pilha_vazia(p) ) {
		pop(p, &b);
		pop(p, &a);
		if( a < b ) {
			m = particionar(v, a, b, comp);
			push(p, a);
			push(p, m-1);
			push(p, m+1);
			push(p, b);
		}
	}
	
	pilha_destroi(&p);
}

uint64_t quickSortSR(int vetor[], size_t tam) {
	uint64_t numComp;
	
	numComp = 0;
	quick_sortSR(vetor, 0, tam-1, &numComp);
	
	return numComp;
}

void max_heapifySR(int v[], int64_t ind, int64_t n, 
						uint64_t *comp) {
	int64_t l, r;
	int64_t maior;
	int64_t j;
	
	j = 1;
	// irá executar uma vez, mas se necessário continua o loop até não precisar
	for(int64_t i = 0; i < j; i++){
		l = esquerda(ind);
		r = direita(ind);
		(*comp)++;
		if( ( l <= n) && (v[l] > v[ind]) ){
			maior = l;
		}else {
			maior = ind;
		}

		if( (r <= n) && (v[r] > v[maior]) ) {
			maior = r;
		}
	
		if(maior != ind) {
			trocar(v, ind, maior);
			ind = maior;
			// o loop irá executar mais uma vez
			j++;
		}
	}
}

void construir_max_heapSR(int v[], int64_t n, uint64_t *numComp){

	for(int64_t i = n/2; i >= 0; i--) {
		max_heapifySR(v, i, n, numComp);
	}
}

void heap_sortSR(int v[], int64_t n, uint64_t *numComp){
	
	construir_max_heapSR(v, n, numComp);
	
	for(uint64_t j = n; j >= 1; j--){
		trocar(v, 0, j);
		max_heapifySR(v, 0, j-1, numComp);
	}
}

uint64_t heapSortSR(int vetor[], size_t tam) {
   uint64_t numComp;
    
    numComp = 0;
	heap_sortSR(vetor, tam-1, &numComp);

    return numComp;
}
