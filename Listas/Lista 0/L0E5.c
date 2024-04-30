/*Escreva um programa que lê um valor n inteiro e positivo e
que calcula a seguinte soma: S = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n.*/

#include <stdio.h>

int main(){
    int n;
    float soma = 0;
    printf("Digite um numero inteiro positivo n: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        soma += 1.0/i;
    }

    printf("Soma: %.2f", soma);
    return 0;
}
