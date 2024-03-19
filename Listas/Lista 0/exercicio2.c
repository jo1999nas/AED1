/*Elaborar um programa que solicita a entrada de 3 valores (a, b, c) e verifica se esses
valores podem formar ou não um triângulo. Você deve considerar que os valores lidos são
inteiros e positivos. Caso os valores formem um triângulo, exiba essa informação e o
valor do perímetro deste triângulo. Se não formarem triângulo, apenas exiba uma mensagem
com essa informação. (Obs.: Para formar um triângulo, cada suposto lado deve ser menor do
que a soma dos outros dois lados.)*/

#include <stdio.h>

int main(){
    int a, b, c, perimetro;

    //Lendo os 3 valores
    printf("Insira o primeiro valor: ");
    scanf("%d", &a);
    printf("Insira o segundo valor: ");
    scanf("%d", &b);
    printf("Insira o terceiro valor: ");
    scanf("%d", &c);

    if(a < b + c && b < a + c && c < a + b){
        printf("Os valores informados podem formar um triangulo. Seu perimetro seria %d.", perimetro);
        perimetro = a + b + c;
    }
    else{
        printf("Os valores informados nao podem formar um triangulo.");
    }

    return 0;
}
