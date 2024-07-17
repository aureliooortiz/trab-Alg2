#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

void aleatorizaVet(int vetor[], int64_t tam){
	for(int i = 0; i < tam; i++){
		vetor[i] = rand() % 101;
	}
}

void imprimeVet(int vetor[], int64_t tam){
	for(int i = 0; i < tam; i++){
		printf("%d ",vetor[i]);
	}
	printf("\n");
}

int main() {
    srand(-10);
    
    char nome[MAX_CHAR];
    uint64_t numComp;
	
    int64_t tamVetor = 4;/*
    int* vetor = (int*)malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }*/
	
	//int vetor[10] = {38, 90, 90, 99, 63, 78, 98, 46, 28, 41};
	//int vetor[4] = {1, 50, -1, 10};
	//int vetor[4] = {-1, 1, 10, 50};
	int vetor[4] = {42, 15, 23, 8};
	
    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());
	
	printf("tamVetor = %ld\n\n",tamVetor);

	// Recursivos
	printf("Merge Sort Recursivo:\n");
	aleatorizaVet(vetor, tamVetor);
	imprimeVet(vetor, tamVetor);
    numComp = mergeSort(vetor, tamVetor);
    printf("\nNumComp: %ld\n", numComp);
    imprimeVet(vetor, tamVetor);
    printf("\n");
    /*
    printf("Quick Sort Recursivo:\n");
    aleatorizaVet(vetor, tamVetor);
	imprimeVet(vetor, tamVetor);
    numComp = quickSort(vetor, tamVetor);
    printf("NumComp: %ld\n", numComp);
    imprimeVet(vetor, tamVetor);
    printf("\n");
    
    printf("Heap Sort Recursivo:\n");
	aleatorizaVet(vetor, tamVetor);
	imprimeVet(vetor, tamVetor);    
    numComp = heapSort(vetor, tamVetor);
    printf("NumComp: %ld\n", numComp);
    imprimeVet(vetor, tamVetor);
    printf("\n");
    
    // Iterativos
    printf("Merge Sort Iterativo:\n");
	aleatorizaVet(vetor, tamVetor);
	imprimeVet(vetor, tamVetor);    
    numComp = mergeSortSR(vetor, tamVetor);
    printf("NumComp: %ld\n", numComp);
    imprimeVet(vetor, tamVetor);
    printf("\n");
    
    printf("Quick Sort Iterativo:\n");
	aleatorizaVet(vetor, tamVetor);
	imprimeVet(vetor, tamVetor);    
    numComp = quickSortSR(vetor, tamVetor);
    printf("NumComp: %ld\n", numComp);
	imprimeVet(vetor, tamVetor);
	printf("\n");
	
	printf("Heap Sort Iterativo:\n");
	aleatorizaVet(vetor, tamVetor);
	imprimeVet(vetor, tamVetor);    
    numComp = heapSortSR(vetor, tamVetor);
    printf("NumComp: %ld\n", numComp);
    imprimeVet(vetor, tamVetor);
    printf("\n");
	
    free(vetor);*/

    return 0;
}
