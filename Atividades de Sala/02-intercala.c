#include <stdio.h>
#define TAM_MAX 10

int main(){
    int vetor1[TAM_MAX], vetor2[TAM_MAX], vetor3[2*TAM_MAX];
    int i, j, elem;
    
    //preenchendo o vetor 1
    for(i = 0; i < TAM_MAX; i++){
        printf("Digite um numero para o vetor 1: ");
        scanf("%d", &elem);
        vetor1[i] = elem;
    }
    
    //preenchendo o vetor 2
    for(i = 0; i < TAM_MAX; i++){
        printf("Digite um numero para o vetor 2: ");
        scanf("%d", &elem);
        vetor2[i] = elem;
    }
    
    //intercalando os 2 vetores
    for(i = 0; i < 2*TAM_MAX; i += 2){
        vetor3[i] = vetor1[j];
        vetor3[i+1] = vetor2[j];
        j++;
    }
    
    //imprimindo o vetor intercalado
    for(i = 0; i < 2*TAM_MAX; i++){
        printf("%d ", vetor3[i]);
    }
    
    return 0;
}
