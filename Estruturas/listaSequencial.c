#include <stdio.h>
#define MAX 10

struct listaSequencial{
    int valores[MAX];   //Vetor com os valores da lista sequencial
    int tamanho;        //Indica a quantidade de elementos da lista
}listaSequencial;

void constroiLista(struct listaSequencial *l){  //Recebe o endereço da lista
    l->tamanho = 0;         //Inicializa a lista, dizendo que ela esta vazia
}

int tamanhoLista(struct listaSequencial l){
    return l.tamanho;       //Retorna o tamanho da lista
}

void imprimeLista(struct listaSequencial l){
    int i;
    if(l.tamanho > 0){                      //Verifica se ha elementos na lista
        printf("\n\nImpressao da lista\n\n");
        for(i = 0; i < l.tamanho; i++){     //Caso hajam, imprime normalmente
            printf("%d ", l.valores[i]);
        }
        printf("\n");
    }
    else printf("\nLista Vazia!");          //Caso contrario, imprime lista vazia
}

int buscaPosicao(struct listaSequencial l, int c){
    int i;                                  //E uma busca sequencial simples
    for(i = 0; i < l.tamanho; i++){
        if(l.valores[i] == c) return i;     //Se achar um valor igual a chave, retorna a posicao i
    }
    return -1;                              //Caso contrario, retorna -1; indicando que nao achou
}

void insereLista(struct listaSequencial *l, int c){
    if(l->tamanho < MAX){                   //Verificamos se a lista esta cheia
        if(buscaPosicao(*l, c) == -1){      //Se a funçao busca posiçao retornar -1, significa que o valor nao foi encontrado, logo podemos cadastrar
            l->valores[l->tamanho] = c;     //O vetor no indice tamanho recebe o valor, adicionado no final
            l->tamanho++;                   //Incrementamos o tamanho
            printf("\nValor %d cadastrado!", c);
        }
        else printf("\nValor %d ja cadastrado!", c);
    }
    else printf("\nLista cheia\n");
}

void removeLista(struct listaSequencial *l, int c){
    int i, indice;
    if(l->tamanho > 0){                     //Verificamos se a lista esta vazia
        indice = buscaPosicao(*l, c);       //Salvamos o indice do elemento removido
        if(indice != -1){                   //Se o indice for -1, o valor nao esta na lista
            l->valores[indice] = l->valores[l->tamanho - 1];        //Atribuimos ao valor a ser removido, o valor guardado na posicao tamanho - 1, (10-1=9)
            l->tamanho--;                                           //Decrementamos o tamanho do vetor
        }
        else printf("\nO valor nao esta na lista!");
    }
    else printf("\nLista Vazia!");
}

int main(){
    struct listaSequencial lista;
    int val, opcao;
    constroiLista(&lista);  //CHAMAR COM O ENDERECO, USANDO &, JA QUE TEREMOS ALTERACAO E PONTEIROS
    do {
        // Exibindo o menu
        printf("\n*** Lista Linear Sequencial ***\n");
        printf("1- Cadastrar\n");
        printf("2- Buscar\n");
        printf("3- Exibir lista\n");
        printf("4- Remover\n");
        printf("5- Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Executando a ação conforme a opção escolhida
        switch (opcao) {
            case 1:
                printf("Digite um numero para inserir: ");
                scanf("%d", &val);
                insereLista(&lista, val);
                break;
            case 2:
                printf("Digite um numero para buscar: ");
                scanf("%d", &val);
                int pos = buscaPosicao(lista, val);
                if (pos != -1) printf("Encontrado na posicao %d\n.", pos);
                else printf("Nao encontrado.\n");
                break;
            case 3:
                imprimeLista(lista);
                break;
            case 4:
                printf("Digite um numero para remover: ");
                scanf("%d", &val);
                removeLista(&lista, val);
                break;
            case 5:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 5);

    return 0;
}

