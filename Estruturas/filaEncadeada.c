#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no *prox;
};

struct no *inicio, *fim;

void inicializaFila() {
    inicio = NULL;
    fim = NULL;
}

int filaVazia() {
    return (inicio == NULL && fim == NULL);
}

void enfileira(int valor) {
    struct no *aux = (struct no *) malloc(sizeof(struct no));
    if (aux != NULL) {
        aux->info = valor;
        aux->prox = NULL;           // Como entra pelo final, o último elemento aponta para NULL
        if (filaVazia()) {          // Se a fila está vazia
            inicio = aux;           // O nó inserido é o primeiro elemento
        }
        else {                      // Se não está vazia
            fim->prox = aux;        // O próximo do antigo último é o aux (novo último)
        }
        fim = aux;                  // O elemento inserido é o novo último
    }
}

void desenfileira() {
    struct no *aux;
    if (!filaVazia()){              // Se a fila não está vazia
        aux = inicio;               // aux recebe o início da lista
        inicio = inicio->prox;      // O novo início será o próximo elemento
        if (inicio == NULL){        // Se o início for NULL
            fim = NULL;             // O fim também deve ser NULL
        }
        free(aux);                  // Libera a memória alocada
    }
    else printf("\nFila Vazia!\n");
}

int main()
{
    inicializaFila();

    return 0;
}
