#include <stdio.h>
#include <stdlib.h>
#define MAX 19000

typedef struct {
    int id;
    char numero[30];
    char data_ajuizamento[25];
    int id_classe;
    int id_assunto;
    int ano_eleicao;
} Processos;

// Prototipagem
void ordenarPorId(Processos processos[], int qtd);
void swapProcesso(Processos *a, Processos *b);
int particao_id(Processos v[], int inf, int sup);
void quicksort_id(Processos v[], int inf, int sup);

int main() {
    FILE *arquivo;
    Processos p[MAX];
    int qtd_processos = 0;

    arquivo = fopen("processos.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char buffer[200];
    fgets(buffer, sizeof(buffer), arquivo); // pula o cabeçalho

    while (fscanf(arquivo, "%d,\"%[^\"]\",%[^,],{%d},{%d},%d\n",
                  &p[qtd_processos].id, p[qtd_processos].numero, p[qtd_processos].data_ajuizamento,
                  &p[qtd_processos].id_classe, &p[qtd_processos].id_assunto, &p[qtd_processos].ano_eleicao) == 6) {
        qtd_processos++;
    }

    fclose(arquivo);

    ordenarPorId(p, qtd_processos);

    return 0;
}

// === Funções auxiliares ===

void swapProcesso(Processos *a, Processos *b) {
    Processos temp = *a;
    *a = *b;
    *b = temp;
}

int particao_id(Processos v[], int inf, int sup) {
    int pivot = v[(inf + sup) / 2].id;
    int i = inf;
    int j = sup;

    while (i <= j) {
        while (v[i].id < pivot) i++;
        while (v[j].id > pivot) j--;
        if (i <= j) {
            swapProcesso(&v[i], &v[j]);
            i++;
            j--;
        }
    }

    return i;
}

void quicksort_id(Processos v[], int inf, int sup) {
    if (inf < sup) {
        int p = particao_id(v, inf, sup);
        quicksort_id(v, inf, p - 1);
        quicksort_id(v, p, sup);
    }
}

void ordenarPorId(Processos processos[], int qtd) {
    quicksort_id(processos, 0, qtd - 1);
}
