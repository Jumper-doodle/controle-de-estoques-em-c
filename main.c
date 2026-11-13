#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char nomes[50][50];
    int quantidade[50];
    char parar = 's';
    char operacao[10];
    int i = 0;

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
            printf("Obrigado por usar o Controle de Estoques! Até a próxima.\n");
            return 0;
        } else if (operacao[0] == '3') {
            FILE *file = fopen("inventory.txt", "r");
            printf("\n============================= Estoque Atual =============================\n");
            if (file == NULL) {
                printf("O estoque está vazio.\n\n");
            } else {
                i = 0;
                while (i < 50 && fscanf(file, " %49[^\n] %d", nomes[i], &quantidade[i]) == 2) {
                    printf("Nome: %s\n", nomes[i]);
                    printf("Quantidade: %d\n\n", quantidade[i]);
                    i++;
                }
                if (i == 0) {
                    printf("O estoque está vazio.\n\n");
                }
                fclose(file);
            }
        } else if (operacao[0] == '2') {
            char itemmenos[50];
            int qr;
            int criado = 0;
            int aqui = -1;

            printf("Digite o nome do item:\n");
            scanf(" %49[^\n]", itemmenos);
            printf("Digite a quantidade a ser removida:\n");
            scanf("%d", &qr);
            while (getchar() != '\n');

            i = 0;
            FILE *file = fopen("inventory.txt", "r");
            if (file != NULL) {
                while (i < 50 && fscanf(file, " %49[^\n] %d", nomes[i], &quantidade[i]) == 2) {
                    if (strcmp(nomes[i], itemmenos) == 0) {
                        criado = 1;
                        aqui = i;
                    }
                    i++;
                    fclose(file)
                }
                
                ;
            }
            if(criado==0) {
                printf("Item não encontrado.");
            }
            else if(qr > quantidade[aqui]) {
                printf("Estoque insuficiente. Quantidade disponível: %d", quantidade[aqui]);
            }
            else if(qr == quantidade[aqui]) {
                printf("Item removido do estoque!");
            }
            else {
                printf("Quantidade atualizada com sucesso!");
                    
            }
        } else if (operacao[0] == '1') {
            char novoitem[50];
            int nq;
            int existe = 0;

            printf("Digite o nome do item:\n");
            scanf(" %49[^\n]", novoitem);
            printf("Digite a quantidade:\n");
            scanf("%d", &nq);
            while (getchar() != '\n');

            i = 0;
            FILE *file = fopen("inventory.txt", "r");
            if (file != NULL) {
                while (i < 50 && fscanf(file, " %49[^\n] %d", nomes[i], &quantidade[i]) == 2) {
                    if (strcmp(nomes[i], novoitem) == 0) {
                        existe = 1;
                    }
                    i++;
                }
                
                
            }
            fclose(file);
            
                file = fopen("inventory.txt", "a");
                if(existe!=1) {
                    fprintf(file, "\n%s", novoitem);
                    fprintf(file, "\n%d", nq);
                    printf("Item adicionado com sucesso!");
                        fclose(file);
        }
                else {
                    
                }
        }

        printf("Deseja realizar outra operação? (s/n): ");
        scanf(" %c", &parar);

        while (parar != 's' && parar != 'S' && parar != 'n' && parar != 'N') {
            printf("Resposta inválida. Por favor, digite s para sim ou n para não: ");
            scanf(" %c", &parar);
        }

        while (getchar() != '\n');

        if (parar == 'n' || parar == 'N') {
            printf("Obrigado por usar o Controle de Estoques! Até a próxima.\n");
            return 0;
        }

    } while (parar == 's' || parar == 'S');

    return 0;
}
