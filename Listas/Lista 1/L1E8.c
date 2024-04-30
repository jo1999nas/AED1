/*Faça um programa que preencha um vetor com 10 números inteiros positivos e crie
um segundo vetor, em que cada posição receberá o fatorial do valor armazenado no 1o
vetor na posição correspondente. Ao final, o programa deve exibir os dois vetores na tela.*/
#include <stdio.h>
#define max 10

void preenche(int *v, int n){
    for(int i = 0; i < n; i++){
        printf("Digite um numero: ", i);
        scanf("%d", &v[i]);
    }
}

void imprime(int *v, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
}

int fatorial(int n){
    int fat = 1;
    for(n; n > 1; n--){
        fat = fat * n;
    }
    return fat;
}

int preencheFat(int *v1, int *v2, int n){
    for(int i = 0; i < n; i++){
        v2[i] = fatorial(v1[i]);
    }
}

int main(){
    int vetor1[max], vetor2[max];
    preenche(vetor1, max);
    preencheFat(vetor1, vetor2, max);
    printf("\nVetor 1\n");
    imprime(vetor1, max);
    printf("\nVetor 2\n");
    imprime(vetor2, max);
    return 0;
}
