/*Faça um programa que leia um número N, que indique quantos números inteiros devem ser lidos a seguir. Para cada número lido, 
apresente uma relação contendo o valor lido e o fatorial desse valor.*/

#include <stdio.h>

int main(){
    int n, i;
    printf("Informe a quantidade de numeros que terao seus fatoriais calculados: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        int num, j, fat = 1;
        printf("Insira um numero: ");
        scanf("%d", &num);
        while(num < 0){
            printf("ERRO! NUMERO INVALIDO! INSIRA OUTRO NUMERO: ");
            scanf("%d", &num);
        }
        j = num;
        for(j; j>1; j--){
            fat = fat*j;
        }
        printf("%d! = %d\n", num, fat);
    }
    return 0;
}
