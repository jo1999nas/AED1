/*Faça um programa que leia duas notas e calcule e exiba a média dessas duas notas para cada aluno de uma turma de 15 estudantes.
Você deve fazer a leitura das notas utilizando um procedimento chamado “leitura” e a média deve ser calculada por uma função
“calcular_media”, que recebe as duas notas por parâmetro e retorna o resultado da média. O procedimento de leitura e a função
da média devem ser chamados na função main, que exibirá as notas e média de cada aluno. Não utilize variáveis globais!*/

#include <stdio.h>

void leitura(float *nota){
    printf("Insira a nota: ");
    scanf("%f", nota);
}

float calcular_media(float n1, float n2){
    return (n1 + n2)/2;
}

int main()
{
    int i = 0;
    while (i < 15){
        float nota1, nota2;
        leitura(&nota1);
        leitura(&nota2);
        printf("Media %.2f\n\n", calcular_media(nota1, nota2));
        i++;
    }
    return 0;
}
