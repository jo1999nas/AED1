/*Faça um programa que leia vários números, uma quantidade indeterminada de vezes,
calcule a soma desses números e a média dos números pares. Exiba esses cálculos na
tela.*/

#include <stdio.h>
#define TAM_MAX 50

int main(){
    int numero, cont_par = 0, soma = 0, soma_par = 0, media_par = 0, quest = 1;

    while(quest = 1){
        printf("Insira um numero: ");
        scanf("%d", &numero);
        soma = soma + numero;
        if (numero % 2 == 0){
            cont_par++;
            soma_par = soma_par + numero;
            media_par = soma_par/cont_par;
        }
        printf("Soma = %d\n", soma);
        printf("Media dos pares = %d\n", media_par);
        printf("Deseja continuar? Pressione 1 para SIM e 0 para NAO: ");
        scanf("%d", &quest);
        printf("\n");
        while(quest !=1 && quest != 0){
            printf("OPCAO INVALIDA\n");
            printf("Deseja continuar? Pressione 1 para SIM e 0 para NAO: ");
            scanf("%d", &quest);
            printf("\n");
        }
    }
    return 0;
}

