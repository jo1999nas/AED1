/*1. Elaborar um programa que efetue a apresentação do valor da conversão em real de
um valor lido em dólar. O programa deve solicitar o valor da cotação do dólar e a
quantidade de dólares disponível com o usuário, para que seja apresentado o valor
correspondente na moeda brasileira.*/

#include <stdio.h>

void cotacao(float *cot){   //A funcao recebe um ponteiro como parametro
    printf("Insira a cotacao atual do dolar: ");
    scanf("%f", cot);       //Nesse caso o scanf() guarda o valor sem usar o &
}

void dolar(float *dol){
    printf("Insira a quantidade de dolares disponivel: ");
    scanf("%f", dol);
}

float conversao(float cot, float dol){
    return cot * dol;
}

int main(){
    float cot, dol; //As variaveis nao podem ter o mesmo nome das funcoes
    cotacao(&cot);  //Chamamos a funcao cotacao passando o endereco da variavel cot como &cot
    dolar(&dol);    //Chamamos a funcao dolar passando o endereco da variavel dol como &dol
    printf("Voce tem R$ %.2f\n", conversao(cot, dol));
    return 0;
}
