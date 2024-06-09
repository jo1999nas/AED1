#include <stdio.h>
#include <stdlib.h>

// Declaração da estrutura do nó
struct no {
    int info;
    struct no *prox;
};

// Ponteiro para o inicio da lista (global, para facilitar)
struct no *inicioL;

// Procedimento para inicializar a lista
void inicializa() {
    inicioL = NULL;
}

// Função que retorna se a lista está vazia
int listaVazia() {
    return inicioL == NULL;
}

// Procedimento para inserir um nó no inicio
void inserirInicio(int valor) {
    struct no *aux;
    aux = (struct no *) malloc(sizeof(struct no));
    if (aux != NULL) {
        aux->info = valor;
        aux->prox = inicioL;
        inicioL = aux;
    }
}

// Procedimento para percorrer a lista
void percorrer() {
    if (!listaVazia()) {
        struct no *aux = inicioL;
        while (aux != NULL) {
            printf("%d ", aux->info);
            aux = aux->prox;
        }
    } else printf("\nLista Vazia!\n");
}

// Procedimento para inserir um nó no final
void inserirFinal(int valor) {
    struct no *aux, *p;                             // Cria dois ponteiros, aux e p
    aux = (struct no *) malloc(sizeof(struct no));  // Aloca memória para aux
    if (aux != NULL) {                              // Se a alocação deu certo...
        aux->info = valor;                          // ...atribui o valor ao campo info de aux
        aux->prox = NULL;                           // O próximo do último elemento sempre será NULL
        if(listaVazia()) {                          // Se a lista estiver vazia...
            inicioL = aux;                          // ...o primeiro elemento também é o último
        }
        else {                                      // Caso contrário...
            p = inicioL;                            // ...P será usada para percorrer a lista
            while (p->prox != NULL){                // Enquanto não chegar no último elemento...
                p = p->prox;                        // ...avança P
            }
            p->prox = aux;                          // Estando no último elemento, o próximo é o nó inserido
        }
    }
}

// Procedimento para remover um nó
void remover(int valor) {
    struct no *aux = inicioL;   // Aux recebe o início da lista
    struct no* ant = NULL;      // Ant é o anterior a aux, nesse caso NULL
    if (!listaVazia()) {        // Se a lista não está vazia
        // Devemos primeiramente buscar o nó a ser removido
        while ((aux != NULL) && (aux->info != valor)) {     // Enquanto não chegar no último nó nem encontrar o valor
            ant = aux;          // Avança ant
            aux = aux->prox;    // Avança aux
        }
        // A lista foi percorrida até o final mas o elemento não foi encontrado
        if (aux == NULL) {
            printf("\nElemento não encontrado!\n");
        }
        else {
            // Se o elemento a ser removido for o primeiro
            if (ant == NULL) {
                inicioL = aux->prox;    // Atualiza o inicioL
            }
            // Se o elemento a ser removido não for o primeiro
            else {
                ant->prox = aux->prox;  // Liga o próx de ant ao próx de aux, pula o elemento removido
            }
            free(aux);  // Libera a memória ocupada por aux
        }
    } else printf("\nLista Vazia!\n");
}

// Função para buscar um determinado valor na lista
struct no *buscar(int valor){
    if (!listaVazia()) {
        struct no *aux = inicioL;
        while ((aux != NULL) && (aux->info != valor)) {
            aux = aux->prox;
        }
        if (aux == NULL) {
            printf("\nElemento não encontrado!\n");
        }
        else return aux;
    }
    else printf("\nLista Vazia!\n");
}

// Lista de exercícios 5

// Escreva uma função que calcule a soma das chaves dos nós de uma lista encadeada
int somaNos() {
    if (!listaVazia()) {
        int soma = 0;
        struct no *aux = inicioL;
        while (aux != NULL) {
            soma = soma + aux->info;
            aux = aux->prox;
        }
        return soma;
    }
    else printf("\nLista Vazia!\n");
}

// Faça um programa que implemente uma função que calcule o número de nós de uma lista encadeada.
int contarNos(){
    if (!listaVazia()) {
        int cont = 0;
        struct no *aux = inicioL;
        while (aux != NULL) {
            cont++;
            aux = aux->prox;
        }
        return cont;
    }
    else printf("\nLista Vazia!\n");
}

/* Considere uma lista encadeada de valores inteiros e implemente uma função para retornar
o número de nós da lista que possuem o campo info com valores maiores do que n.*/
int nosMaioresQue(int valor) {
    if (!listaVazia()) {
        int cont = 0;
        struct no *aux = inicioL;
        while (aux != NULL) {
            if (aux->info > valor){
                cont++;
            }
            aux = aux->prox;
        }
        return cont;
    }
    else printf("\nLista Vazia!\n");
}

/*Implemente uma função que retorne o valor armazenado no último nó de uma lista
encadeada de números inteiros.*/
int ultimoNo() {
    if (!listaVazia()) {
        struct no *aux = inicioL;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        return aux->info;
    }
    else printf("\nLista Vazia!\n");
}

/*Considere listas de valores inteiros e implemente uma função que dada uma lista encadeada
e um valor inteiro n, retire da lista todas as ocorrências de n retornando a lista resultante. Ao
final, o programa deve imprimir a lista resultante.*/
void removeValores(int valor) {
    if (!listaVazia()) {
        int cont = 0;
        struct no *aux = inicioL;
        while (aux != NULL) {
            if (aux->info == valor){
                cont++;
            }
            aux = aux->prox;
        }
        for (int i = 0; i < cont; i++){
            remover(valor);
        }
    }
    else printf("\nLista Vazia!\n");
}

/*Implemente uma função que dados um valor e uma posição, a função insere o elemento
valor na posição pos da lista simplesmente encadeada. Para isso, um novo nó deve ser alocado
e ligado aos demais. O valor de pos é um número, que ser for 2, por exemplo, indica que o
novo nó alocado será o segundo nó da lista.*/
void inserePosicao(int valor, int posicao) {
    if (!listaVazia()) {
        struct no *aux;
        aux = (struct no *) malloc(sizeof(struct no));
        if (aux != NULL){
            int cont = 1;
            struct no *ant = NULL;
            struct no *p = inicioL;
            while (cont < posicao && p->prox != NULL) { // Precisa achar o valor ou chegar ao fim da lista
                cont++;
                ant = p;
                p = p->prox;
            }
            aux->info = valor;
            if (ant != NULL) { // Se ant não for NULL, significa que não estamos inserindo no início da lista
                ant->prox = aux;
            } else { // Se ant for NULL, estamos inserindo no início da lista
                inicioL = aux;
            }
            aux->prox = p;
        }
    }
    else printf("\nLista Vazia!\n");
}


int main(){
    inicializa();

    return 0;
}

