#include <stdio.h>
#include <stdlib.h>

// Declaração da estrutura de um nó
struct no {
    int info;
    struct no *esq, *dir;
};

// Ponteiro para a raiz da árvore
struct no *raiz;

// Procedimento para incializar a árvore
void inicializarArvore() {
    raiz = NULL;
}

// Função para criar um nó
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

// Procedimento para inserir um nó na árvore
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

// Procedimento para imprimir um nó da árvore
void imprimeNo(struct no *raiz) {
    if (raiz != NULL) {
        printf("%d ",raiz->info);
    }
}

// Procedimento para percorrer a árvore em pre-ordem
void preOrdem(struct no *raiz) {
    if (raiz != NULL) {
        printf("%d ",raiz->info);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

// Procedimento para percorrer a árvore em ordem
void emOrdem(struct no *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ",raiz->info);
        emOrdem(raiz->dir);
    }
}

// Procedimento para percorrer a árvore em pós-ordem
void posOrdem(struct no *raiz) {
    if(raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ",raiz->info);
    }
}

// Função para buscar um nó na árvore
struct no* buscaNo(int valor) {
    struct no *aux = raiz;
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

// Procedimento para liberar a memória da árvore
void liberarArvore(struct no *raiz) {
    if (raiz == NULL) {
        return;
    }
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

// Função que calcula a altura da árvore
int alturaArvore(struct no *raiz) {
    if (raiz == NULL) {     // Se a árvore for vazia, não tem altura
        return -1;
    }
    int esquerda = alturaArvore(raiz->esq);     // Calculando a altura da subárvore à esquerda
    int direita = alturaArvore(raiz->dir);      // Calculando a altura da subárvore à direita
    if (esquerda > direita) {
        return esquerda + 1;    // Retorna a altura da subárvore à esquerda mais 1
    }
    else {
        return direita + 1;     // Retorna a altura da subárvore à direita mais 1
    }
}

// Função que calcula o número de nós da árvore
int contaNos(struct no *raiz) {
    if (raiz == NULL) {     // Se a árvore for vazia, não tem nós
        return 0;
    }
    // A quantidade de nós é a quantidade das duas subárvores mais da raíz
    return contaNos(raiz->esq) + contaNos(raiz->dir) + 1;
}

// Função que calcula o número de folhas da árvore
int contaFolhas(struct no *raiz) {
    if (raiz == NULL) {     // Se a árvore for vazia, não tem folhas
        return 0;
    }
    // Se um nó não tem filhos, conta como folha
    else if (raiz->esq == NULL && raiz->dir == NULL) {
        return 1;   // Esse return 1 que efetivamente faz a conta
    }
    else {
        // Por fim, contamos a quantidade das duas subárvores
        return contaFolhas(raiz->esq) + contaFolhas(raiz->dir);
    }
}

// Função que encontra o nó com o menor valor armazenado na árvore
struct no *menorValor(struct no *raiz) {
    // O menor valor de uma árvore binária de busca é o mais a esquerda
    // Se o filho esquerdo da raíz não existe, a raíz é o menor elemento
    if (raiz->esq == NULL) {
        return raiz;
    }
    struct no *aux = raiz;  // Criamos um ponteiro auxiliar para percorrer a árvore
    // Enquanto houver filho à esquerda, avançamos
    while (aux->esq != NULL){
        aux = aux->esq;
    }
    return aux;     // Por fim, retornamos aux
}

// Função que encontra o nó com o maior valor armazenado na árvore
struct no *maiorValor(struct no *raiz) {
    if (raiz->dir == NULL) {
        return raiz;
    }
    struct no *aux = raiz;
    while (aux->dir != NULL) {
        aux = aux->dir;
    }
    return aux;
}

int main() {
    inicializarArvore();
    return 0;
}
