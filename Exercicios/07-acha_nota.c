/*Faça um programa que leia um vetor A com 10 notas de uma turma. Em
seguida, o programa deve solicitar que o usuário digite uma nota
qualquer e deve procurar por esta nota no vetor, escrevendo a
mensagem “ACHEI”, se a nota estiver armazenada no vetor A ou “NÃO
ACHEI”, caso contrário. Implemente uma função para realizar essa
busca.*/

#include <stdio.h>
#define tamanho 10

int main(){
    int vetor[tamanho], i, alvo, aux = 0;
    //criando o vetor de notas
    for(i = 0; i < tamanho; i++){
        printf("Insira um numero: ");
        scanf("%d", &vetor[i]);
    }
    //buscando uma nota no vetor
    printf("Insira uma nota para buscar: ");
    scanf("%d", &alvo);

    for(i = 0; i < tamanho; i++){
        if(vetor[i] == alvo){
            aux = 1;
        }
    }

    if(aux == 1){
        printf("ACHEI");
    }
    else{
        printf("NAO ACHEI");
    }

    return 0;
}

