#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no *prox;
};

struct no *topo;

void inicializaPilha() {
    topo = NULL;
}

int pilhaVazia() {
    return topo == NULL;
}

void empilhar(int valor) {
    struct no *aux = (struct no *) malloc(sizeof(struct no));
    if (aux != NULL) {
        aux->info = valor;      // Armazena o valor
        aux->prox = topo;       // O próximo do novo nó é o antigo topo
        topo = aux;             // Atualiza o topo para o nó recem-inserido
    }
}

void desempilhar() {
    struct no *aux;
    if (!pilhaVazia()) {
        aux = topo;             // Atribui o topo a aux
        topo = topo->prox;      // O novo topo é o elemento abaixo
        free(aux);              // Libera a memória de aux;
    }
    else printf("\nLista Vazia!\n");
}

void mostraTopo() {
    printf("\nTopo: %d\n", topo->info);
}

int main() {
    inicializaPilha();
    empilhar(1);
    empilhar(2);
    empilhar(3);
    mostraTopo();
    desempilhar();
    mostraTopo();
    empilhar(7);
    empilhar(6);
    mostraTopo();
    return 0;
}
