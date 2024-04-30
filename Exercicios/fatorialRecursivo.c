#include <stdio.h>

int fatorialRecursivo(int n){
    if (n <= 1){
        return 1;
    }
    else{
        return n*(fatorialRecursivo(n-1));
    }
}

int main(){
    int numero;
    printf("Insira um numero: ");
    scanf("%d", &numero);
    printf("%d! = %d\n", numero, fatorialRecursivo(numero));
    return 0;
}

