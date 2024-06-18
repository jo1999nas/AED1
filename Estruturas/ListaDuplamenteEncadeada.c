#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;                   // Campo para informação
    struct no *ant, *prox;      // Ponteros para os nós anterior e próximo
};

struct no *inicioE;             // Inicio da esquerda
struct no *inicioD;             // Inicio da direita

void inicializarLista() {
    inicioE = NULL;
    inicioD = NULL;
}

int listaVazia() {
    return inicioD == NULL;
}

void inserirEsquerda(int valor) {
    struct no *aux;
    aux = (struct no *) malloc(sizeof(struct no));
    if (aux != NULL) {
        aux->info = valor;
        aux->ant = NULL;
        aux->prox = NULL;
        // Se o nó inserido for o primeiro
        if (listaVazia()) {
            inicioE = aux;
            inicioD = aux;
        }
        else {
            aux->prox = inicioE;
            inicioE->ant = aux;
            inicioE = aux;
        }
    }
}

void inserirDireita(int valor) {
    struct no *aux;
    aux = (struct no *) malloc(sizeof(struct no));
    if (aux != NULL) {
        aux->info = valor;
        aux->ant = NULL;
        aux->prox = NULL;
        // Se o nó inserido for o primeiro...
        if (listaVazia()) {
            inicioE = aux;
            inicioD = aux;
        }
        else {
            aux->ant = inicioD;
            inicioD->prox = aux;
            inicioD = aux;
        }
    }
}

void percorrerEsquerda() {
    if (!listaVazia()) {
        struct no * aux = inicioE;
        while (aux != NULL) {
            printf("%d ", aux->info);
            aux = aux->prox;
        }
    }
    else printf("\nLista Vazia!\n");
}

void percorrerDireita() {
    if (!listaVazia()) {
        struct no * aux = inicioD;
        while (aux != NULL) {
            printf("%d ", aux->info);
            aux = aux->ant;
        }
    }
    else printf("\nLista Vazia!\n");
}

struct no *buscaLDE(int valor) {
    if (!listaVazia()) {
        struct no *aux = inicioE;
        while (aux != NULL && aux->info != valor) {
            aux = aux->prox;
        }
        if (aux != NULL) {
            return aux;
        }
        else{
            printf("\nValor não encontrado!\n");
            return NULL;
        }
    }
    else {
        printf("\nLista Vazia!\n");
        return NULL;
    }
}

void remover(int valor) {
    if (!listaVazia()) {
        struct no * aux = buscaLDE(valor);
        if (aux != NULL) {
            // Se só houver um elemento na lista
            if (inicioE == inicioD) {
                inicioE = NULL;
                inicioD = NULL;
            }
            // Se for o primeiro elemento
            else if (aux == inicioE) {
                inicioE = aux->prox;
                inicioE->ant = NULL;
            }
            // Se for o último elemento
            else if (aux == inicioD) {
                inicioD = aux->ant;
                inicioD->prox = NULL;
            }
            // Se for um elemento qualquer
            else {
                struct no *anterior = aux->ant;
                struct no *posterior = aux->prox;
                anterior->prox = posterior;
                posterior->ant = anterior;
            }
            free(aux);
        }
        else printf("\nValor não encontrado!\n");
    }
    else printf("\nLista Vazia!\n");
}

int main() {

    return 0;
}

