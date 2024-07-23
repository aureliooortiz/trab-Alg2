#ifndef PILHA_H_
#define PILHA_H_

#include <stdlib.h>

// Pilha focada em indices
struct pilha{
    size_t altura;
    size_t topo;
    
    int *valor;
} ;

// Inicializa a pilha, com altura e memoria
unsigned int pilha_cria(struct pilha *p, size_t tamanho); // Retorna 1 para ERRO

// Destroi a pilha
void pilha_destroi(struct pilha *p);

// Nao verifica se eh impossivel empilhar
void push(struct pilha *p, int64_t valor);

// Nao verifica se eh impossivel desempilhar
// Retorna o desempilhado (int)
int pop(struct pilha *p);

/**
 * Verifica se a pilha esta vazia
 * Retorna 1 para VAZIA
 * Retorna 0 para NAO VAZIA
 * */
unsigned int pilha_vazia(struct pilha p);

#endif // PILHA_H_
