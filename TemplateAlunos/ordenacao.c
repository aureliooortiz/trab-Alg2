#include "ordenacao.h"

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

void imprimeVetor(int vetor[], int64_t tam){
	for(int i = 0; i < tam; i++){
		printf("%d ",vetor[i]);
	}
	printf("\n");
}

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
	int *aux;
	
	aux = malloc((b+1) * sizeof(int));
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

void max_heapifyRec(int v[], int64_t ind, int64_t n, 
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
	/*
	printf("\ninter: %lu\n", *comp);
	printf("\nind: %ld\n", ind);
	printf("\nl: %ld\n", l);
	printf("\nr:%ld\n", r);
	printf("\nmaior: %ld\n", maior);
	*/
	if(maior != ind) {
		trocar(v, ind, maior);
		//imprimeVetor(v, n+1);
		max_heapifyRec(v, maior, n, comp);
	}

}

void construir_max_heap(int v[], int64_t n, uint64_t *numComp){

	for(int64_t i = n/2; i >= 0; i--) {
		//printf("\nFora de mH i: = %ld\n", i);
		max_heapifyRec(v, i, n, numComp);
	}
}

void heap_sort(int v[], int64_t n, uint64_t *numComp){
	
	construir_max_heap(v, n, numComp);
	
	for(uint64_t j = n; j >= 1; j--){
		trocar(v, 0, j);
		max_heapifyRec(v, 0, j-1, numComp);
	}
}

uint64_t heapSort(int vetor[], size_t tam) {
    uint64_t numComp;
    
    numComp = 0;
	heap_sort(vetor, tam-1, &numComp);

    return numComp;
}
/*
uint64_t mergeSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t quickSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t heapSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}
*/
