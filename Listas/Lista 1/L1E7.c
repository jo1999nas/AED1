/*Faça um programa que implemente uma função recursiva que receba por parâmetro
um número inteiro positivo n e imprima todos os números naturais de 0 a N em ordem
crescente.*/
#include <stdio.h>

int seqRecursiva(int a){
    if (a < 0){
        return;
    }
    else{
        seqRecursiva(a - 1);
        printf("%d ", a);
    }
}

int main(){
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    seqRecursiva(num);
    return 0;
}

