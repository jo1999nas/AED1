/*Faça um programa que leia um número e gere todos os números primos entre 1 e
este número fornecido, exibindo-os na tela. O programa deve ter uma função que
determina se um número é primo ou não.*/
#include <stdio.h>

int ehPrimo(int n){
    if(n <= 1){
        return 0;
    }
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int numero;
    printf("Insira um número: ");
    scanf("%d", &numero);

    for(int i = 0; i <= numero; i++){
        if(ehPrimo(i) == 1){
            printf("%d\n", i);
        }
    }

    return 0;
}
