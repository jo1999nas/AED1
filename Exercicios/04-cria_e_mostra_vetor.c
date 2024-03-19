/*Faça um programa que leia 20 números inteiros e após a leitura imprima os números informados.*/

#include <stdio.h>
#define TAM_MAX 20

void cria_vetor(int vet[]){
    int i, elem;
    for(i = 0; i < TAM_MAX; i++){
        printf("Insira um numero: ");
        scanf("%d", &elem);
        vet[i] = elem;
    }
    printf("\n");
}

void mostra_vetor(int vet[]){
    int i;
    for(i = 0; i < TAM_MAX; i++){
        printf("%d ", vet[i] );
    }
}

int main(){
    int vetor[TAM_MAX];
    cria_vetor(vetor);
    mostra_vetor(vetor);
    return 0;
}

