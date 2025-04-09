#include "func.h"  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Processo *LerArquivo(const char *nomeArquivo) {
    int N = 0;
    char linha[2048];

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("ERRO! Falha ao abrir o arquivo.\n");
        return NULL;
    }

    Processo *processos = (Processo *)malloc(NumProcesso * sizeof(Processo));
    if (processos == NULL) {
        printf("Nao foi possivel alocar memoria para a tabela!\n");
        fclose(arquivo);
        return NULL;
    }

    // Ignora o cabeçalho
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) && N < NumProcesso) {
        // Remove quebras de linha do final da string
        linha[strcspn(linha, "\r\n")] = '\0';

        // Pula linhas vazias
        if (strlen(linha) == 0) continue;

        char *token;
        int campo = 0;
        int i = 0;
        int len = strlen(linha);
        int pos = 0;

        while (campo < 6 && pos < len) {
            char valor[TAM_MAX] = "";
            int j = 0;

            if (linha[pos] == '{') {
                // campo multivalorado
                pos++;
                while (linha[pos] != '}' && linha[pos] != '\0') {
                    valor[j++] = linha[pos++];
                }
                valor[j] = '\0';
                pos++; // pula '}'
                if (linha[pos] == ',') pos++;
            } else if (linha[pos] == '"') {
                // campo entre aspas
                pos++;
                while (linha[pos] != '"' && linha[pos] != '\0') {
                    valor[j++] = linha[pos++];
                }
                valor[j] = '\0';
                pos++; // pula '"'
                if (linha[pos] == ',') pos++;
            } else {
                // campo simples
                while (linha[pos] != ',' && linha[pos] != '\0' && linha[pos] != '\n') {
                    valor[j++] = linha[pos++];
                }
                valor[j] = '\0';
                if (linha[pos] == ',') pos++;
            }

            switch (campo) {
                case 0: strncpy(processos[N].id, valor, TAM_MAX); break;
                case 1: strncpy(processos[N].numero, valor, TAM_MAX); break;
                case 2: strncpy(processos[N].data_ajuizamento, valor, TAM_MAX); break;
                case 3: strncpy(processos[N].id_classe, valor, TAM_MAX); break;
                case 4: strncpy(processos[N].id_assunto, valor, TAM_MAX); break;
                case 5: processos[N].ano_eleicao = atoi(valor); break;
            }

            campo++;
        }

        N++;
    }

    fclose(arquivo);
    return processos;
}


// Função auxiliar para trocar dois processos
void Swap(Processo *a, Processo *b) {
    Processo temp = *a;
    *a = *b;
    *b = temp;
}

// Partição para QuickSort por ID
int Particao(Processo *V, int inf, int sup) {
    Processo Pivo = V[(inf + sup) / 2];
    int i = inf;
    int j = sup;

    while (i <= j) {
        while (strcmp(V[i].id, Pivo.id) < 0) i++;
        while (strcmp(V[j].id, Pivo.id) > 0) j--;
        if (i <= j) {
            Swap(&V[i], &V[j]);
            i++;
            j--;
        }
    }
    return i;
}

// QuickSort crescente por ID
void QuickSortID(Processo *V, int inf, int sup) {
    if (inf < sup) {
        int P = Particao(V, inf, sup);
        QuickSortID(V, inf, P - 1);
        QuickSortID(V, P, sup);
    }
}
