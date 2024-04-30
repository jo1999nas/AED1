#include <stdio.h>
#include <string.h>

#define desc_max 240
#define comp_max 20

struct horario {
    int hora;
    int min;
    int seg;
};

struct data {
    int dia;
    int mes;
    int ano;
};

struct compromisso {
    struct horario h;
    struct data d;
    char desc[desc_max];
};

int main() {
    int i, continuar;
    int comp_cont = 0;
    struct compromisso comp[comp_max];

    //Ler o compromisso
    for (i = 0; i < comp_max; i++) {
        //Perguntando a data do compromisso
        printf("Qual a data (DIA : MES : ANO) do compromisso? ");
        scanf("%d%d%d", &comp[i].d.dia, &comp[i].d.mes, &comp[i].d.ano);

        //Perguntando a hora do compromisso
        printf("Qual o horario (HORA : MINUTO : SEGUNDO) do compromisso? ");
        scanf("%d%d%d", &comp[i].h.hora, &comp[i].h.min, &comp[i].h.seg);

        //Limpando o buffer de entrada
        while (getchar() != '\n');

        //Perguntando a descricao do compromisso
        printf("Insira uma descricao para o compromisso: ");
        fgets(comp[i].desc, sizeof(comp[i].desc), stdin);
        comp[i].desc[strcspn(comp[i].desc, "\n")] = '\0';

        //Perguntando se o usuario deseja continuar
        printf("\nDeseja adicionar mais um compromisso?\nPressione 1 para SIM\nPressione 0 para NAO\n");
        scanf("%d", &continuar);
        while (continuar != 1 && continuar != 0) {
            printf("\nOPCAO INVALIDA");
            printf("\nDeseja adicionar mais um compromisso?\nPressione 1 para SIM\nPressione 0 para NAO\n");
            scanf("%d", &continuar);
        }
        if (continuar == 0) break;
        comp_cont++;
    }
    //Imprimindo os compromissos salvos
    printf("\n\nCOMPROMISSOS AGENDADOS\n\n");
    for (i = 0; i <= comp_cont; i++) {
        printf("Compromisso %d\n", i + 1);
        printf("Data: %2d/%2d/%4d\n", comp[i].d.dia, comp[i].d.mes, comp[i].d.ano);
        printf("Hora: %2d:%2d:%2d\n", comp[i].h.hora, comp[i].h.min, comp[i].h.seg);
        printf("Descricao: %s\n\n", comp[i].desc);
    }

    return 0;
}
