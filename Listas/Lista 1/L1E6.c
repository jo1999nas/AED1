/*Faça uma função recursiva para fazer a multiplicação de dois números (a e b). A
função receberá dois números positivos não nulos a e b e deve retornar o resultado de a × b.*/
#include <stdio.h>

int multiplicacaoRecursiva(int a, int b){
    if(a == 0 || b == 0)
        return 0;
    if(b == 1)
        return a;
    return a + multiplicacaoRecursiva(a, b - 1);
}

int main(){
    int fator1, fator2;
    printf("Insira dois numeros positivos nao nulos: ");
    scanf("%d%d", &fator1, &fator2);
    printf("%d * %d = %d", fator1, fator2, multiplicacaoRecursiva(fator1, fator2));

    return 0;
}

