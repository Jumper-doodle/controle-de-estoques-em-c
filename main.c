#include <stdio.h>
#include <stdlib.h>

int main() {
    char nomes[50][50];
    int quantidade[50];
    char parar;
    char operacao[10];
    int i = 0;

    FILE *file = fopen("inventory.txt", "r+");
    if (file == NULL) {
        file = fopen("inventory.txt", "w+");
    }

    do {
        printf("===============================\n");
        printf("Controle de Estoque\n");
        printf("===============================\n");
        printf("Selecione uma opção:\n");
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Estoque\n");
        printf("4. Sair\n");
        printf("Opção: ");
        
        fgets(operacao, sizeof(operacao), stdin);

        while (operacao[0] < '1' || operacao[0] > '4' || operacao[1] != '\n') {
            printf("Opção inválida! Tente novamente: ");
            fgets(operacao, sizeof(operacao), stdin);
        }

        if (operacao[0] == '4') {
            printf("Tudo bem, até a próxima!\n");
            fclose(file);
            return 0;
        } else if (operacao[0] == '3') {
            rewind(file);
            i = 0;
            printf("\n============================= Estoque Atual =============================\n");
            
            while (i < 50 && fscanf(file, " %49[^\n] %d", nomes[i], &quantidade[i]) == 2) {
                printf("Nome: %s\n", nomes[i]);
                printf("Quantidade: %d\n\n", quantidade[i]);
                i++;
            }
            
            if (i == 0) {
                printf("O estoque está vazio.\n\n");
            }
        } else if (operacao[0] == '2') {
            
        } else if (operacao[0] == '1') {
            
        }

        printf("Deseja realizar outra operação? (s/n): ");
        scanf(" %c", &parar);

        while (parar != 's' && parar != 'S' && parar != 'n' && parar != 'N') {
            printf("Resposta inválida. Por favor, digite s para sim ou n para não: ");
            scanf(" %c", &parar);
        }

        while (getchar() != '\n');

        if (parar == 'n' || parar == 'N') {
            printf("Obrigado por usar o sistema! Até a próxima.\n");
            fclose(file);
            return 0;
        }

    } while (parar == 's' || parar == 'S');

    fclose(file);
    return 0;
}
