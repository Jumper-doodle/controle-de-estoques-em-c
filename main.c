#include <stdio.h>

int main() {
    char nomes[20][50];
    int quantidade[20];
    char parar;
    char operacao[10];
  int i=0;
  FILE *file = fopen("inventory.txt", "w");
    do {
        printf("===============================\n");
        printf("       Controle de Estoque\n");
        printf("===============================\n");
        printf("Selecione uma opção:\n");
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Estoque\n");
        printf("4. Sair\n");
        printf("Opção:\n");
        
        fgets(operacao, sizeof(operacao), stdin);
        while (operacao[0] < '1' || operacao[0] > '4' || operacao[1] != '\n') {
            printf("Opção inválida! Tente novamente.\n");
            fgets(operacao, sizeof(operacao), stdin);

        }
        
        if (operacao[0] == '4') {
            printf("Tudo bem, até a próxima!\n");
            return 0;
        } 
        else if (operacao[0] == '3') {
            while(fscanf(file, "%s", nomes[i]) == 1){
                fscanf(file, "%d", &quantidade[i]);
                printf("=============================
        Estoque Atual
============================="
                printf("Nome: %s\n", nomes[i]);
                printf("Quantidade: %d\n\n", quantidade[i]);
                i++;
}
        else if (operacao[0] == '2') {
            
            }
            
            }
            
            printf("Deseja realizar outra operação? (s/n):\n");
            scanf(" %c", &parar);
            
            while (parar != 's' && parar != 'S' && parar != 'n' && parar != 'N') {
                printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
                scanf(" %c", &parar);
            }
            
            
            while (getchar() != '\n');
            
            if (parar == 'n' || parar == 'N') {
                printf("Obrigado por usar a calculadora! Até a próxima.\n");
                return 0;
            }
        }
    } while (parar == 's' || parar == 'S');

    fclose(file);
    return 0;
}
