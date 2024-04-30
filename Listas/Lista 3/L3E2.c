/*Considere que o programa do exercício anterior preencha os valores do vetor de
forma ordenada. Faça uma busca por um valor informado pelo usuário. Utiliza a
busca binária.*/
#include <stdio.h>
#define max 20

void preenche(int *v, int n){
    for(int i = 0; i < n; i++){
        printf("Digite um numero: ", i);
        scanf("%d", &v[i]);
    }
}

int buscaBinaria(int *vet, int tam, int x){
    int inicio = 0, fim = tam - 1, meio;
    while(inicio <= fim){
        meio = (inicio + fim)/2;
        if (vet[meio] == x) return meio;
        else if (vet[meio] > x) fim = meio - 1;
        else inicio = meio + 1;
    }
    return -1;
}

void interpretaBusca(int pos){
    if (pos != -1){
        printf("\nValor encontrado na posição %d!\n", pos);
    }
    else{
        printf("\nValor não encontrado\n");
    }
}

int main(){
    int chave, posicao, vetor[max];
    preenche(vetor, max);
    printf("Insira um valor para buscar: ");
    scanf("%d", &chave);
    posicao = buscaBinaria(vetor, max, chave);
    interpretaBusca(posicao);
    return 0;
}

