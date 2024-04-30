/*Faça um programa para ler um conjunto de números inteiros, armazenando-o em vetor
e calcular a soma de todos os valores armazenados. Os conjuntos têm 10 elementos cada.
Ao final, o programa deve exibir todos os valores do vetor e o somatório calculado.
OBS.:
    O vetor deve ser declarado como uma variável local, dentro do main;
    Os dados do vetor devem ser lidos por um procedimento de leitura, aplicando
        corretamente o uso de passagem de parâmetros;
    A impressão dos dados deve ser feita por um procedimento e chamada no
        main para que seja executada.*/

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

int somaVetor(int *v, int n){
    int i, soma = 0;
    for(i = 0; i < n; i++){
        soma += v[i];
    }
    return soma;
}

int main(){
    int vetor[max];
    preenche(vetor, max);
    imprime(vetor, max);
    printf("\nSomatorio: %d", somaVetor(vetor, max));
    return 0;
}

