/*Uma agência de uma cidade do interior tem, no máximo, 10.000 clientes.
Faça um programa que leia o número da conta e o saldo de cada cliente. A
leitura de clientes termina quando for digitado -999 para número da conta
ou quando atingir 10.000 clientes. O programa deve calcular e imprimir o
total de clientes com saldo negativo, o total de clientes da agência e o
saldo da agência.*/

#include <stdio.h>
#define CLI_MAX 10000

struct cliente{
    int conta;
    float saldo;
}cliente;

int main(){
    int i, clientes = 0, negativos = 0;
    float saldo_ag = 0.00;
    struct cliente cli[CLI_MAX];

    //Entrando com os dados dos clientes
    for(i = 0; i < CLI_MAX; i++){
        printf("Insira o numero da conta: ");
        scanf("%d", &cli[i].conta);
        if(cli[i].conta == -999){   //Se -999 for digitado, para a entrada de dados
            break;
        }
        else{
            printf("Insira o saldo do cliente: ");
            scanf("%f", &cli[i].saldo);
            clientes++; //Contabiliza o numero total de clientes
            if(cli[i].saldo < 0){
                negativos++;    //Se o saldo for negativo, o programa contabiliza como negativado
            }
        }
    }

    for(i = 0; i < clientes; i++){
        saldo_ag = saldo_ag + cli[i].saldo;
    }


    //Imprimindo os dados
    printf("\n\nDADOS DA AGENCIA\n\n");
    printf("Clientes com saldo negativo: %d\n", negativos);
    printf("Numero total de clientes: %d\n", clientes);
    printf("Saldo total da agencia: %.2f\n", saldo_ag);

    return 0;
}
