/*Faça um programa que preencha um vetor de 10 posições com números inteiros, exiba
todo o vetor informado e o maior valor encontrado nesse vetor.*/

#include <stdio.h>
#define max 10

void preenche(int *v, int n){
    for(int i = 0; i < n; i++){
        printf("Digite um numero: ", i);
        scanf("%d", &v[i]);
    }
}

void imprime(int *v, int n){
    for (int i = 0; i < max; i++){
        printf("%d ", v[i]);
    }
}

int maiorValor(int *v, int n){
    int maior = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > maior){
            maior = v[i];
        }
    }
    return maior;
}

int main(){
    int vetor[max], maiorNum;
    preenche(vetor, max);
    imprime(vetor, max);
    printf("\n\nO maior valor no vetor e: %d", maiorValor(vetor, max));
}

