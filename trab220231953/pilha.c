#include "pilha.h"

unsigned int pilha_cria(struct pilha *p, size_t tamanho) {
    
    p->valor = (int *) malloc (tamanho * sizeof(int));
    if (p->valor == NULL) return 1;

    p->altura = tamanho;
    p->topo = 0;

    return 0;
}

void push(struct pilha *p, int64_t valor) {

    p->valor[(p->topo)] = valor;
    p->topo++;
}

int pop(struct pilha *p) {

    p->topo--;
    return p->valor[(p->topo)];
}

unsigned int pilha_vazia(struct pilha p) { return (p.topo == 0) ? 1 : 0; }

void pilha_destroi (struct pilha *p) {
    
    free(p->valor);
    p->topo = 0;
    p->altura = 0;
}
