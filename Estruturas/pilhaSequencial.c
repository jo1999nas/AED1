#include <stdio.h>
#define max 10

struct pilhaSeq{
    int valores[max];
    int topo;
};

void inicializaPilha(int *topo){
    *topo = -1;             //Inicializa a pilha com o topo sendo a posicao -1
}

int pilhaCheia(int topo){   //Verifica se a pilha está cheia.
    return (topo == max-1); //Retorna verdadeiro se o topo for a ultima posicao e falso caso contrario
}

int pilhaVazia(int topo){   //Verifica se a pilha está vazia.
    return (topo == -1);    //Retorna verdadeiro se o topo for -1 e falso caso contrario
}

int mostraTopo(struct pilhaSeq p){
    if(pilhaVazia(p.topo) == 0){
        printf("\nTopo: %d\n", p.valores[p.topo]);
    }
    else printf("\nPilha vazia!\n");
}

void empilhar(struct pilhaSeq *p, int c){
    if(!pilhaCheia(p->topo)){
        p->topo++;
        p->valores[p->topo] = c;
    }
    else printf("\nPilha cheia!\n");
}

void desempilhar(struct pilhaSeq *p){
    if(!pilhaVazia(p->topo)){
        p->topo--;
    }
    else printf("\nPilha vazia!\n");
}

int main(){
    struct pilhaSeq pilha;
    inicializaPilha(&pilha.topo);
    int opcao, valor;

    do {
        // Exibindo o menu
        printf("\n*** Pilha Sequencial ***\n");
        printf("1- Empilhar\n");
        printf("2- Desempilhar\n");
        printf("3- Mostrar topo\n");
        printf("4- Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Executando a ação conforme a opção escolhida
        switch (opcao) {
            case 1:
                printf("\nInsira um valor para empilhar: ");
                scanf("%d", &valor);
                empilhar(&pilha, valor);
                break;
            case 2:
                desempilhar(&pilha);
                break;
            case 3:
                mostraTopo(pilha);
                break;
            case 4:
                printf("\nSaindo do programa.\n");
                break;
            default:
                printf("\nOpcao invalida.\n");
        }
    } while (opcao != 4);
    return 0;
}

