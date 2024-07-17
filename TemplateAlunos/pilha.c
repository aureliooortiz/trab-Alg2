#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/*
 * Cria e retorna uma nova pilha.
 * Retorna NULL em caso de erro de alocação.
*/ 
struct pilha *pilha_cria (){
	struct pilha *p;	

	p = malloc(sizeof(struct pilha));
	if(!p) return NULL;
	
	p->topo = NULL;
	p->tamanho = 0;
	
	return p;
}

/* Desaloca toda memoria da pilha e faz pilha receber NULL. */
void pilha_destroi (struct pilha **pilha){
	struct nodo *aux;
	
	if(!pilha || !(*pilha)) return;
	
	while((*pilha)->topo != NULL){
		aux = (*pilha)->topo;
		(*pilha)->topo = (*pilha)->topo->prox;
		free(aux);
	}
	free(*pilha);
	*pilha = NULL;
}

/*
 * Insere dado na pilha (politica LIFO). Retorna 1
 * em caso de sucesso e 0 em caso de falha.
*/
int push (struct pilha *pilha, int64_t dado){
	struct nodo *nodo;
	
	if(!pilha) return 0;
	nodo = malloc(sizeof(struct nodo));
	if(!nodo) return 0;

	nodo->chave = dado;
	nodo->prox = pilha->topo;
	pilha->topo = nodo;
	pilha->tamanho++;

	return 1;
}	

/*
 * Remove o topo (politica LIFO) e retorna o elemento 
 * no parametro dado. A funcao retorna 1 em caso de 
 * sucesso e 0 no caso da pilha estar vazia.
*/
int pop (struct pilha *pilha, int64_t *dado){
	struct nodo *aux;
	
	if(!pilha) return 0;

	if(pilha->tamanho == 0) return 0;
	
	*dado = pilha->topo->chave;
	aux = pilha->topo;
	pilha->topo = aux->prox;
	pilha->tamanho--;
	free(aux);	
	
	return 1;
}

/*
 * Similar ao pop, mas retorna o elemento dado sem remove-lo. 
 * A funcao retorna 1 em caso de sucesso e 0 no caso 
 * da pilha estar vazia.
*/
int pilha_topo (struct pilha *pilha, int *dado){
	if(!pilha) return 0;
	/* retorna 0 no caso da pilha estar vazia */
	if(pilha->tamanho == 0) return 0;
	
	*dado = pilha->topo->chave;
	
	return 1;
}

/* Retorna o numero de elementos da pilha, que pode ser 0. */
int pilha_tamanho (struct pilha *pilha){
	if(!pilha) return -1;

	return pilha->tamanho;
}

/* Retorna 1 se pilha vazia, 0 em caso contrario. */ 
int pilha_vazia (struct pilha *pilha){
	if(!pilha) return 0;

	if(pilha->tamanho == 0){
		return 1;
	}
	return 0;
}

