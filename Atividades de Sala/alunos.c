#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 30
#define TAM_NOME 50

struct Aluno {
    int matricula, cpf, telefone;
    char nome[TAM_NOME];
};

struct Aluno turma[MAX_ALUNOS];
int num_alunos = 0;

void cadastrarAluno() {
    if (num_alunos >= MAX_ALUNOS) {
        printf("Capacidade maxima de alunos atingida!\n");
        return;
    }

    struct Aluno aluno;

    printf("Digite o numero de matricula do aluno: ");
    scanf("%d", &aluno.matricula);
    while (getchar() != '\n');
    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';
    printf("Digite o CPF do aluno: ");
    scanf("%d", &aluno.cpf);
    printf("Digite o telefone so aluno: ");
    scanf("%d", &aluno.telefone);

    turma[num_alunos] = aluno;
    num_alunos++;

    printf("Aluno cadastrado com sucesso!\n");
}

void buscarAluno() {
    int matricula;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);

    int i;
    for (i = 0; i < num_alunos; i++) {
        if (turma[i].matricula == matricula) {
            printf("Matricula: %d\n", turma[i].matricula);
            printf("Nome: %s\n", turma[i].nome);
            printf("CPF:  %d\n", turma[i].cpf);
            printf("Telefone:  %d\n", turma[i].telefone);
            return;
        }
    }

    printf("Aluno nao encontrado!\n");
}

void exibirAlunos() {
    int i;
    for (i = 0; i < num_alunos; i++) {
        printf("Matricula: %d\n", turma[i].matricula);
        printf("Nome: %s\n", turma[i].nome);
        printf("CPF:  %d\n", turma[i].cpf);
        printf("Telefone:  %d\n\n", turma[i].telefone);
    }
}

void removerAluno() {
    int matricula;
    printf("Digite a matricula do aluno a ser removido: ");
    scanf("%d", &matricula);

    int i;
    for (i = 0; i < num_alunos; i++) {
        if (turma[i].matricula == matricula) {
            int j;
            for (j = i; j < num_alunos - 1; j++) {
                turma[j] = turma[j + 1];
            }
            num_alunos--;
            printf("Aluno removido com sucesso!\n");
            return;
        }
    }

    printf("Aluno nao encontrado!\n");
}

int main() {
    int opcao;

    do {
        printf("\n*** Sistema de alunos ***\n");
        printf("1- Cadastrar aluno\n");
        printf("2- Buscar aluno pela matricula\n");
        printf("3- Exibir os dados dos alunos\n");
        printf("4- Remover um aluno\n");
        printf("5- Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                buscarAluno();
                break;
            case 3:
                exibirAlunos();
                break;
            case 4:
                removerAluno();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}
