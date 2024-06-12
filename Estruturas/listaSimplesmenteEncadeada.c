#include <stdio.h>
#include <stdlib.h>

struct no{              // Declaração da estrutura do nó
    int info;           // Campo que armazena a informação
    struct no *prox;    // Ponteiro para o proximo elemento da lista
}no;

struct no *inicioL;     // Ponteiro para o incio da lista

void inicializaLista(){ // Essa função não precisa de parametros
    inicioL = NULL;     // O ponteiro aponta para lugar nenhum, logo a lista está vazia
}

int listaVazia(struct no *inicioDaLista){   // A função recebe o inicio da lista como parametro
    return inicioDaLista == NULL;           // Se o inicio da lista é em lugar nenhum, logo ela está vazia
}

void inserirInicio(int valor){
    struct no *aux;             // Criamos uma variavel auxiliar
    aux = (struct no*) malloc(sizeof(struct no));   // Alocamos espaço para esse ponteiro
    if (aux != NULL){           // Se aux foi alocado corretamente
        aux->info = valor;      // Salvamos o valor no campo info de aux
        aux->prox = inicioL;    // O proximo de aux aponta para o inicio (inserção no inicio)
        inicioL = aux;          // Atualizamos o inicio da lista para o valor recem adicionado
    }
}

void inserirFinal(int valor){
    struct no *aux, *p;         // Criamos duas variaveis: aux e p
    aux = (struct no*) malloc(sizeof(struct no));   // Alocamos espaço para aux
    if (aux != NULL){           // Se aux foi alocado corretamente
        aux->info = valor;      // Salvamos o valor no campo info de aux
        aux->prox = NULL;       // O proximo de aux aponta para NULL (inserção no final)
        if (listaVazia(inicioL)){   // Se a lista esta vazia
            inicioL = aux;          // Aux é o primeiro elemento
        }
        else{                       // Se a lista não está vazia
            p = inicioL;            // P vai receber o inicio da lista
            while(p->prox != NULL)  // Enquanto o proximo de p for diferente de NULL
                p = p->prox;        // Avançamos p
            p->prox = aux;          // Quando o proximo de p for NULL, apontaremos ele para aux, inserindo no final
        }
    }
}

void percorrer(){
    if (!listaVazia(inicioL)){
        struct no *aux; // Criamos uma variavel auxiliar
        aux = inicioL;  // A variavel auxiliar recebe o inicio da lista
        while (aux != NULL){            // Enquanto aux for diferente de vazio
            printf("%d ", aux->info);   // Imprime o conteudo do nó
            aux = aux-> prox;           // Avança a varivel aux com o endereço em aux->prox
        }
    } else printf("\nLista Vazia!\n");  // Caso a lista esteja vazia informe
}

void remover(int valor){
    struct no *ant = NULL;      // Rastreia o nó anterior ao nó atual
    struct no *aux = inicioL;   // Usada para percorrer a lista, começa no inicio da lista
    if (!listaVazia(inicioL)){  // Se a lista não estiver vazia...
        while(aux != NULL && aux->info != valor){   // Enquanto não atingimos o fim da lista e o valor de info de não for igual ao valor buscado
            ant = aux;          // Atualiza ant para o nó atual
            aux = aux->prox;    // Move aux para o próximo nó da lista
        }
        if (aux == NULL)        // Se percorremos a lista inteira e não encontramos um nó com o valor buscado...
            printf("\nElemento não encontrado!\n"); // Imprimimos uma mensagem informando que o elemento não foi encontrado
        else{                   // Se encontramos um nó com o valor buscado precisamos remove-lo
            if (ant == NULL)            // Se o nó a ser removido é o primeiro nó da lista...
                inicioL = aux->prox;    // Atualiza inicioL para apontar para o próximo nó (aux->prox)
            else                        // Se o nó a ser removido não é o primeiro.
                ant->prox = aux->prox;  // Ajusta o prox do nó anterior (ant) para pular o nó atual (aux)
            free(aux);                  // Libera a memória alocada para o nó que está sendo removido.
        }
    }
    else printf("\nLista Vazia!\n");  // Caso a lista esteja vazia informe
}

int main() {
    int opcao, valor;

    do {
        printf("\n*****Lista Simplesmente Encadeada*****\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no final\n");
        printf("3. Remover elemento\n");
        printf("4. Exibir lista\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite o valor a ser adicionado: ");
                scanf("%d", &valor);
                inserirInicio(valor);
                break;
            case 2:
                printf("\nDigite o valor a ser adicionado: ");
                scanf("%d", &valor);
                inserirFinal(valor);
                break;
            case 3:
                printf("\nDigite o valor a ser removido: ");
                scanf("%d", &valor);
                remover(valor);
                break;
            case 4:
                percorrer();
                break;
            case 5:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

