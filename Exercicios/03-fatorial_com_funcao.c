/*Faça um programa que leia um número N, que indique quantos números inteiros devem ser lidos a seguir. Para cada número lido, 
apresente uma relação contendo o valor lido e o fatorial desse valor. O fatorial deve ser calculado por uma funcao chamada 
fatorial*/

#include <stdio.h>

int fatorial(int num){
    int fat = 1;
    for(num; num > 1; num--){
        fat = fat*num;
    }
    return fat;
}

int main(){
    int n, i;
    printf("Informe a quantidade de numeros: ");
    scanf("%d", &n);
    for(i=0; i < n; i++){
        int num;
        printf("Insira um numero: ");
        scanf("%d", &num);
        while (num < 0){
            printf("ERRO! NUMERO INVALIDO! INSIRA OUTRO NUMERO: ");
            scanf("%d", &num);
        }
        printf("%d! = %d\n", num, fatorial(num));
    }
    return 0;
}
