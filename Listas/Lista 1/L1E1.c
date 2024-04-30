/*Faça um programa para ler um conjunto de números reais, armazenando-o em vetor e
calcular o quadrado dos elementos deste vetor, armazenando o resultado em outro vetor.
Os conjuntos têm 10 elementos cada. Imprimir todos os dados.*/

#include <stdio.h>
#define max 10

void preenche(int *v, int n){
    for(int i = 0; i < n; i++){
        printf("Digite um numero: ", i);
        scanf("%d", &v[i]);
    }
}

void dobraVetor(int *v1, int *v2, int n){
    for (int i = 0; i < n; i++){
        v2[i] = v1[i] * v1[i];
    }
}

void imprime(int *v, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
}

int main(){
    int vet1[max], vet2[max];
    preenche(vet1, max);
    printf("\nVETOR 1\n");
    imprime(vet1, max);
    printf("\nVETOR 2\n");
    dobraVetor(vet1, vet2, max);
    imprime(vet2, max);
    return 0;
}


