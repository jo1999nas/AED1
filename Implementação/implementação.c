//Integrantes: Jonas Albuquerque, Juliana Campos, Pamella Japson, Pedro Henrique Yugue, Pedro Paulo Granjeiro

#include <stdio.h>
#define TAMANHO 10

void preencheVetor(int *vet, int tam){
    int elem;
    for(int i = 0; i < tam; i++){
        printf("Insira um numero: ");
        scanf("%d", &elem);
        vet[i] = elem;
    }
}

void imprimeVetor(int *vet, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", vet[i] );
    }
}

void interpretaBusca(int pos){
    if (pos != -1){
        printf("\nValor encontrado na posição %d!\n", pos);
    }
    else{
        printf("\nValor não encontrado\n");
    }
}

int buscaSequencial(int *vet, int tam, int x){
    for(int i = 0; i < tam; i++){
        if(vet[i] == x){
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int *vet, int tam, int x){
    int inicio = 0, fim = tam - 1, meio;
    while(inicio <= fim){
        meio = (inicio + fim)/2;
        if (vet[meio] == x) return meio;
        else if (vet[meio] > x) fim = meio - 1;
        else inicio = meio + 1;
    }
    return -1;
}

void bubbleSort(int *vet, int tam){
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < (tam - 1 - i); j++){
            if (vet[j] > vet[j + 1]){
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int *vet, int tam){
    int i, j, min, temp;
    for (i = 0; i < tam - 1; i++){
        min = i;
        for (j = i + 1; j < tam; j++){
            if (vet[j] < vet[min]){
                min = j;
            }
        }
        temp = vet[i];
        vet[i] = vet[min];
        vet[min] = temp;
    }
}

int main() {
    int vetor[TAMANHO];
    int op, opSec, chave, posicao;


    do {
        //Menu de opções
        printf("\n\n==================== MENU ====================\n");
        printf("1. Preencher vetor\n");
        printf("2. Buscar por um valor no vetor\n");
        printf("3. Ordenar o vetor\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                preencheVetor(vetor, TAMANHO);
                imprimeVetor(vetor, TAMANHO);
                break;
            case 2:
                printf("\nQual método de busca deve ser utilizado?\n");
                printf("1. Busca sequencial\n");
                printf("2. Busca binária\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &opSec);
                switch (opSec) {
                    case 1:
                        //Usando a busca sequencial
                        printf("\nDigite um número: ");
                        scanf("%d", &chave);
                        posicao = buscaSequencial(vetor, TAMANHO, chave);
                        interpretaBusca(posicao);
                        break;
                    case 2:
                        //Usando a busca binaria
                        printf("\nDigite um número: ");
                        scanf("%d", &chave);
                        posicao = buscaBinaria(vetor, TAMANHO, chave);
                        interpretaBusca(posicao);
                        break;
                    default:
                        printf("\nOpcao invalida! Tente novamente.\n");
                        break;
                }
                break;
            case 3:
                printf("\nQual método de ordenação deve ser utilizado?\n");
                printf("1. Bubble Sort\n");
                printf("2. Selection Sort\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &opSec);
                switch (opSec)
                {
                case 1:
                    //Usando o Bubble Sort
                    bubbleSort(vetor, TAMANHO);
                    imprimeVetor(vetor, TAMANHO);
                    break;
                case 2:
                    //Usando o Insertion Sort
                    selectionSort(vetor, TAMANHO);
                    imprimeVetor(vetor, TAMANHO);
                    break;
                default:
                    printf("Opção invalida! Tente novamente.\n");
                    break;
                }
                break;
            case 4:
                printf("\nSaindo do programa!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
        }

    } while (op != 4);

    return 0;
}
