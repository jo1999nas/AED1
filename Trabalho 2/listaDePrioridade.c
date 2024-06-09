#include <stdio.h>
#include <stdlib.h>

#define max 10

// Função para trocar dois elementos
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função que recebe o indice de um elemento na lista e retorna o indice de seu pai
int indicePai(int indice) {
    return indice / 2;
}

// Função que recebe o indice de um elemento na lista e retorna o indice de seu filho a esquerda
int indiceFilhoEsquerdo(int indice) {
    return 2 * indice;
}

// Função que recebe o indice de um elemento na lista e retorna o indice de seu filho a direita
int indiceFilhoDireito(int indice) {
    return 2 * indice + 1;
}

// Função para corrigir violações subindo no heap
void corrigeSubindo(int heap[], int indice) {
    if (indice == 1){
        return; // Se estiver na raiz, não há mais correções para fazer
    }
    int pai = indicePai(indice);

    if (heap[indice] > heap[pai]) {             // Se o elemento é maior que o pai
        troca(&heap[indice], &heap[pai]);       // Troca com o pai
        corrigeSubindo(heap, pai);              // Chama recursivamente para corrigir em direção à raiz
    }
}

// Função para corrigir violações descendo no heap
void corrigeDescendo(int heap[], int indice, int tamanho) {
    int direito = indiceFilhoDireito(indice);
    int esquerdo = indiceFilhoEsquerdo(indice);

    int maior = indice; // Inicialmente, o maior é o próprio índice

    // Se o filho direito existe e é maior que o atual maior
    if (direito <= tamanho && heap[direito] > heap[maior]) {
        maior = direito;
    }
    // Se o filho esquerdo existe e é maior que o atual maior
    if (esquerdo <= tamanho && heap[esquerdo] > heap[maior]) {
        maior = esquerdo;
    }
    if (maior != indice) {                      // Se o maior não é o próprio índice
        troca(&heap[indice], &heap[maior]);     // Troca com o maior filho
        corrigeDescendo(heap, maior, tamanho);  // Chama recursivamente para corrigir em direção às folhas
    }
}

// Função para inserir um elemento no heap
void inserirPrioridade(int heap[], int *tamanho, int valor) {
    if (*tamanho >= max) {                      // Se o heap estiver cheio
        printf("\nLista cheia!\n");
        return;
    }
    (*tamanho)++;                               // Incrementa o tamanho do heap
    heap[*tamanho] = valor;                     // Insere o valor na última posição
    corrigeSubindo(heap, *tamanho);             // Corrige violações subindo
}

// Função para remover um elemento do heap
void removerPrioridade(int heap[], int *tamanho) {
    if (*tamanho < 1) {                         // Se o heap estiver vazio
        printf("\nLista vazia!\n");
        return;
    }
    troca(&heap[1], &heap[*tamanho]);           // Troca o elemento a ser removido com o último
    (*tamanho)--;                               // Decrementa o tamanho do heap
    corrigeDescendo(heap, 1, *tamanho);         // Corrige violações descendo
    printf("\nValor com maior prioridade removido!\n");
}

// Função para alterar a prioridade de um nó já existente
void alterarPrioridade(int heap[], int tamanho, int posicao, int novaPrioridade) {
    if (posicao < 1 || posicao > tamanho) {     // Verifica se a posição é válida
        printf("\nPosição inválida!\n");
        return;
    }
    heap[posicao] = novaPrioridade;             // Atualiza a prioridade do nó

    // Corrige a posição do nó no heap
    // Primeiro, verifica se a prioridade aumentou ou diminuiu
    int pai = indicePai(posicao);
    if (pai > 0 && heap[posicao] > heap[pai]) { // Se a prioridade aumentou, corrige subindo
        corrigeSubindo(heap, posicao);
    } else {                                    // Se a prioridade diminuiu, corrige descendo
        corrigeDescendo(heap, posicao, tamanho);
    }
}

// Função para exibir o heap
void exibirHeap(int heap[], int tamanho) {
    printf("\nLista de Prioridade: ");
    for (int i = 1; i <= tamanho; i++) {        // Percorre o heap
        printf("%d ", heap[i]);                 // Exibe os elementos
    }
    printf("\n");
}

// Função principal
int main() {
    int heap[max];
    int tamanho = 0;
    int opcao, valor, posicao, novaPrioridade;
    do {
        printf("\n***** Lista de Prioridades *****\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Alterar\n");
        printf("4. Exibir\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            // Inserir
            case 1:
                printf("\nDigite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserirPrioridade(heap, &tamanho, valor);
                break;
            // Remover
            case 2:
                removerPrioridade(heap, &tamanho);
                break;
            // Alterar
            case 3:
                printf("\nDigite a posição do elemento: ");
                scanf("%d", &posicao);
                printf("Digite a nova prioridade: ");
                scanf("%d", &novaPrioridade);
                alterarPrioridade(heap, tamanho, posicao, novaPrioridade);
                break;
            // Exibir
            case 4:
                exibirHeap(heap, tamanho);
                break;
            // Sair
            case 5:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 5);
    return 0;
}
