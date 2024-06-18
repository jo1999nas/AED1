#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no *esq, *dir;
};

struct no *raiz;

void inicializarArvore() {
    raiz == NULL;
}

struct no *criaNo(int valor) {
    struct no *novo;
    novo = (struct no *) malloc(sizeof(struct no));
    if (novo != NULL) {
        novo->info = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

void inserirNo(int valor) {
    struct no *novo = criaNo(valor);
    if (novo != NULL) {
        // Se a árvore está vazia, insere na raíz
        if (raiz == NULL) {
            raiz = novo;
            return;
        }
        struct no *aux = raiz;
        while (1) {
            // Inserindo na subárvore à esquerda
            if (valor < aux->info) {
                if (aux->esq == NULL) {
                    aux->esq = novo;
                    return;
                }
                aux = aux->esq;
            }
            // Inserindo na subárvore à direita
            else {
                if (aux->dir == NULL) {
                    aux->dir = novo;
                    return;
                }
                aux = aux->dir;
            }
        }
    }
}

void preOrdem(struct no *raiz) {
    if (raiz != NULL) {
        printf("%d ",raiz->info);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void emOrdem(struct no *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ",raiz->info);
        emOrdem(raiz->dir);
    }
}

void posOrdem(struct no *raiz) {
    if(raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ",raiz->info);
    }
}

struct no* buscaNo(int valor) {
    no *aux = raiz;
    while (aux != NULL) {
        // Valor encontrado
        if (valor == aux->info) return aux;
        else {
            // Se o valor é menor que o do nó
            if (valor < aux->info) {
                // Busca na subárvore à esqueda
                aux = aux->esq;
            }
            // Se o valor é maior que o do nó
            else {
                // Busca na subárvore à direita
                aux = aux->dir;
            }
        }
    }
    return NULL;    // Nó não encontrado
}

void liberarArvore(struct no *raiz) {
    if (aux == NULL) {
        return;
    }
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

int main() {
    inserirNo(25);
    inserirNo(16);
    inserirNo(20);
    inserirNo(7);
    inserirNo(9);
    inserirNo(8);
    inserirNo(2);
    inserirNo(3);
    preOrdem(raiz);
    printf("\n\n");
    emOrdem(raiz);
    printf("\n\n");
    posOrdem(raiz);
    printf("\n\n");
    return 0;
}
