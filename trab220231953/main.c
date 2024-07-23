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
	
	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
	
	for (int i = 0; i < 4; i++) {
    	int64_t tamVetor = 1000000;
    	int* vetor = (int*)malloc( tamVetor * sizeof(int) );
    	if (vetor == NULL) {
    	    printf("Falha fatal. Impossível alocar memoria.");
    	    return 1;
    	}
		// imprimeVet(vetor, tamVetor); 
	
		printf("tamVetor = %ld\n\n",tamVetor);
	
		// Recursivos 
		printf("Merge Sort Recursivo:\n");
		aleatorizaVet(vetor, tamVetor);
		numComp = mergeSort(vetor, tamVetor);
		printf("NumComp: %ld\n", numComp);
		printf("\n");

		printf("Quick Sort Recursivo:\n");
		aleatorizaVet(vetor, tamVetor);
		numComp = quickSort(vetor, tamVetor);
		printf("NumComp: %ld\n", numComp);
		printf("\n");
   
		printf("Heap Sort Recursivo:\n");
		aleatorizaVet(vetor, tamVetor);  
		numComp = heapSort(vetor, tamVetor);
		printf("NumComp: %ld\n", numComp);
		printf("\n");
    
		// Iterativos
		printf("Merge Sort Iterativo:\n");
		numComp = mergeSortSR(vetor, tamVetor);
		printf("NumComp: %ld\n", numComp);
		printf("\n");
		
		printf("Quick Sort Iterativo:\n");
		aleatorizaVet(vetor, tamVetor);
		numComp = quickSortSR(vetor, tamVetor);
		printf("NumComp: %ld\n", numComp);
		printf("\n");
		
		printf("Heap Sort Iterativo:\n");
		aleatorizaVet(vetor, tamVetor);
		numComp = heapSortSR(vetor, tamVetor);
		printf("NumComp: %ld\n", numComp);
		printf("\n");
		
		free(vetor);
		
		switch (i) {
			case 1:
				tamVetor = 10.000.000;
				break; 
			case 2:
				tamVetor = 100.000.000;
				break;
			case 3:
				tamVetor = 1.000.000.000;
				break;
		}
	}	
		
    return 0;
}
