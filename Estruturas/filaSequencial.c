#include <stdio.h>
#define max 10

struct filaSeq{
    int valores[max];           //Guarda os valores na fila
    int inicio, fim, tamanho;   //inicio = remoção; fim = inserção; tamanho = número de elementos na fila
};

void inicializaFila(int *inicio, int *fim, int *tamanho){
    *inicio = -1;       //O inicio da fila e -1
    *fim = -1;          //O final da fila e -1
    *tamanho = 0;       //O tamanho da fila e 0
}

int filaVazia(int tamanho){
    return (tamanho == 0);          //Retorna 1 se a fila esta vazia e 0 caso contrario
}

int filaCheia(int tamanho){
    return (tamanho == max);        //Retorna 1 se o tamanho for igual ao maximo e 0 caso contrario
}

void filaTamanho(int tamanho){
    printf("\nTamanho da Fila: %d\n", tamanho);
}

void filaProximo(struct filaSeq f){
    if(!filaVazia(f.tamanho)){                              //Confere se a lista não está vazia
        printf("\nProximo: %d\n", f.valores[f.inicio]);     //Mostra o próximo elemento a sair
    }
    else{
        printf("\nFila Vazia!\n");
    }
}

void filaUltimo(struct filaSeq f){
    if(!filaVazia(f.tamanho)){                          //Confere se a lista não esta vazia
        printf("\nUltimo: %d\n", f.valores[f.fim]);     //Mostra o último elemento a chegar
    }
    else{
        printf("\nFila Vazia!\n");
    }
}

void enfileirar(struct filaSeq *f, int c){
    if(!filaCheia(f->tamanho)){                 //Se a fila nao esta cheia
        f->fim++;                               //Move o fim para frente
        f->valores[f->fim % max] = c;           //Atribui o valor a posição atual do fim (resto da divisão de fim por tamanho maximo)
        if(f->inicio == -1){                    //Verifica se o inicio ainda esta em -1, se a lista esta vazia
            f->inicio++;                        //Nesse caso, como so há um elemento, o inicio anda uma posição e fica junto ao fim
        }
        f->tamanho = f->fim - f->inicio + 1;    //Incrementa o tamanho da fila
    }
    else{
        printf("\nFila Cheia!\n");               //Caso a lista esteja cheia, a função avisa
    }
}

void desenfileirar(struct filaSeq *f){
    if(!filaVazia(f->tamanho)){             //Se a fila não está vazia
        f->inicio++;
        f->tamanho = f->fim - f->inicio + 1;
    }
    else{
        printf("\nFila Vazia!\n");           //Caso a lista esteja vazia, a função avisa
    }
}

int main(){
    struct filaSeq fila;
    inicializaFila(&fila.inicio, &fila.fim, &fila.tamanho);   //Inicializamos a fila passando o endereço do inicio, do fim e do tamanho como parametros
    int opcao, valor;

    // Menu principal
    do {
        printf("\n******* Fila Sequencial *******\n");
        printf("1- Enfileirar\n");
        printf("2- Desenfileirar\n");
        printf("3- Mostrar próximo\n");
        printf("4- Mostrar último\n");
        printf("5- Mostrar tamanho\n");
        printf("6- Sair\n");
        printf("Informe sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe o valor a ser enfileirado: ");
                scanf("%d", &valor);
                enfileirar(&fila, valor);
                break;
            case 2:
                desenfileirar(&fila);
                break;
            case 3:
                filaProximo(fila);
                break;
            case 4:
                filaUltimo(fila);
                break;
            case 5:
                filaTamanho(fila.tamanho);
                break;
            case 6:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
    while (opcao != 6);

    return 0;
}

