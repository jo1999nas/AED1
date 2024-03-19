/*Elabore um programa em C que leia 2 vetores com 5 valores inteiros cada e determine o vetor soma.*/

#include <stdio.h>
#define TAM_MAX 5

void cria_vetor(int vet[]){
    int i, elem;
    for(i = 0; i < TAM_MAX; i++){
        printf("Insira um numero: ");
        scanf("%d", &elem);
        vet[i] = elem;
    }
    printf("\n");
}

void soma_vetor(int vet1[], int vet2[], int soma[]){
    int i;
    for(i = 0; i < TAM_MAX; i++){
        soma[i] = vet1[i] + vet2[i];
    }
}

void mostra_vetor(int vet[]){
    int i;
    for(i = 0; i < TAM_MAX; i++){
        printf("%d ", vet[i] );
    }
}

int main(){
    int vetor1[TAM_MAX], vetor2[TAM_MAX], vetor3[TAM_MAX];

    cria_vetor(vetor1);
    cria_vetor(vetor2);
    soma_vetor(vetor1, vetor2, vetor3);
    mostra_vetor(vetor3);
    return 0;
}

