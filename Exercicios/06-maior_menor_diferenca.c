/*Escreva um programa em C que leia um vetor de 15 elementos inteiros e calcule e exiba a diferença entre
 o maior e o menor elemento armazenado, assim como as posições que os mesmos ocupam.*/

#include <stdio.h>
#define TAM_MAX 15

int main(){
    int i, elem, maior, menor, diferenca, vetor[TAM_MAX];
    //criando o vetor
    for(i = 0; i < TAM_MAX; i++){
        printf("Insira um numero: ");
        scanf("%d", &elem);
        vetor[i] = elem;
    }
    //achando o maior elemento
    maior = vetor[0];
    for(i = 0; i < TAM_MAX; i++){
        if(vetor[i] >= maior){
            maior = vetor[i];
        }
    }
    printf("Maior: %d\n", maior);
    //achando o menor elemento
    menor = vetor[0];
    for(i = 0; i < TAM_MAX; i++){
        if(vetor[i] <= menor){
            menor = vetor[i];
        }
    }
    printf("Menor: %d\n", menor);
    //calculando a diferenca
    diferenca = maior - menor;
    printf("Diferenca: %d\n", diferenca);

    return 0;
}
