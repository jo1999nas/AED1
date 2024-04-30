/*Elabore um programa que leia vários registros de animais contendo os dados: nome,
raça, data de nascimento e sexo. Os registros devem ser lidos enquanto o usuário desejar. O
máximo de animais cadastrados é 50. Ao final, todos os registros devem ser impressos.*/

#include <stdio.h>

// Definição da estrutura Animal
struct Animal {
    char nome[50];
    char raca[50];
    char data_nascimento[15];
    char sexo;
};

int main() {
    struct Animal animais[50];
    int num_animais = 0;
    char continuar;

    do {
        // Verifica se ainda há espaço para mais animais
        if (num_animais >= 50) {
            printf("Limite de animais atingido.\n");
            break;
        }

        // Solicita os dados do animal
        printf("Digite o nome do animal: ");
        scanf("%s", animais[num_animais].nome);

        printf("Digite a raca do animal: ");
        scanf("%s", animais[num_animais].raca);

        printf("Digite a data de nascimento do animal (DD/MM/AAAA): ");
        scanf("%s", animais[num_animais].data_nascimento);

        printf("Digite o sexo do animal (M/F): ");
        scanf(" %c", &animais[num_animais].sexo);

        num_animais++;

        // Verifica se o usuário deseja continuar cadastrando animais
        printf("Deseja cadastrar outro animal? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    // Imprime os registros de animais cadastrados
    printf("\nRegistros de Animais:\n");
    for (int i = 0; i < num_animais; i++) {
        printf("Animal %d:\n", i + 1);
        printf("Nome: %s\n", animais[i].nome);
        printf("Raca: %s\n", animais[i].raca);
        printf("Data de Nascimento: %s\n", animais[i].data_nascimento);
        printf("Sexo: %c\n", animais[i].sexo);
        printf("\n");
    }

    return 0;
}

