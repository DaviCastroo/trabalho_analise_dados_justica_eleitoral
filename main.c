#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int main() {
    char nome_arquivo[256];

    printf("Digite o nome do arquivo CSV: ");
    scanf("%255s", nome_arquivo);

    Processo *processos = LerArquivo(nome_arquivo);
    if (!processos) return 1;

    QuickSortID(processos, 0, NumProcesso - 1);

    FILE *saida = fopen("ordenado_por_id.csv", "w");
    if (!saida) {
        printf("Erro ao criar o arquivo de saída.\n");
        free(processos);
        return 1;
    }

    fprintf(saida, "\"id\",\"numero\",\"data_ajuizamento\",\"id_classe\",\"id_assunto\",\"ano_eleicao\"\n");


    for (int i = 0; i < NumProcesso; i++) {
        // Verifica se o processo está realmente preenchido
        if (strlen(processos[i].id) == 0 || strlen(processos[i].numero) == 0) {
            continue; // pula registro inválido
        }
    
        fprintf(saida, "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",%d\n",
                processos[i].id,
                processos[i].numero,
                processos[i].data_ajuizamento,
                processos[i].id_classe,
                processos[i].id_assunto,
                processos[i].ano_eleicao);
    }
    

    fclose(saida);
    free(processos);

    printf("Arquivo 'ordenado_por_id.csv' gerado com sucesso.\n");
    return 0;
}
