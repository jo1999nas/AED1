/*Elabore um programa que preencha um vetor de valores inteiros de 20 posições e
ao final faça uma busca sequencial por um valor, a ser informado pelo usuário.*/
#include <stdio.h>
#define max 20

void preenche(int *v, int n){
    for(int i = 0; i < n; i++){
        printf("Digite um numero: ", i);
        scanf("%d", &v[i]);
    }
}

int buscaSequencial(int *v, int n, int x){
    for(int i = 0; i < n; i++){
        if(v[i] == x){
            return i;
        }
    }
    return -1;
}

void interpretaBusca(int pos){
    if (pos != -1){
        printf("\nValor encontrado na posição %d!\n", pos);
    }
    else{
        printf("\nValor não encontrado\n");
    }
}

int main(){
    int chave, posicao, vetor[max];
    preenche(vetor, max);
    printf("Insira um valor para buscar: ");
    scanf("%d", &chave);
    posicao = buscaSequencial(vetor, max, chave);
    interpretaBusca(posicao);
    return 0;
}

