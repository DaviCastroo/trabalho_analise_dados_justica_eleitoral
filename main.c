#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"




int main() {
    int opcao;

    Processo *processos = nomeArquivo();
    if (!processos) return 1;
  
    do {
        printf("\n===== MENU INTERATIVO =====\n");
        printf("1. Ordenar por ID (ordem crescente)\n");
        printf("2. Ordenar por data de ajuizamento (mais atual primeiro)\n");
        printf("3. Contar processos por ID de classe\n");
        printf("4. Contar assuntos totais e unicos\n");
        printf("5. Listar processos com multiplos assuntos\n");
        printf("6. Dias de tramitacao de um processo\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                QuickSortID(processos, 0, NumProcesso - 1);
                saidaID(processos, NumProcesso);
                printf("Processos ordenados por ID (crescente).\n");
                break;
            case 2:
              //  QuickSortDataMaisAtual(processos, 0, NumProcesso - 1);
                printf("Processos ordenados por data de ajuizamento (mais recente primeiro).\n");
                break;
            case 3: {
                char id_classe[100];
                printf("Digite o ID da classe: ");
                scanf(" %s", id_classe);
              //  QntdProcessosID_classe(processos, (unsigned char *)id_classe);
                break;
            }
            case 4:
               // QntdProcessosID_assunto(processos);
                break;
            case 5:
              //  QntdAssuntosMultiplos(processos);
                break;
            case 6: {
                char id_processo[100];
                printf("Digite o ID do processo: ");
                scanf(" %s", id_processo);
               // QuantosDias(processos, (unsigned char *)id_processo);
                break;
            }
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    // criar função para as saidas

    return 0;
}
