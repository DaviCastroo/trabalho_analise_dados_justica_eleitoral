#ifndef FUNC_H
#define FUNC_H

#define TAM_MAX 50
#define NumProcesso 18392

typedef struct {
  char id[TAM_MAX];
  char numero[TAM_MAX];
  char data_ajuizamento[TAM_MAX];
  char id_classe[TAM_MAX];
  char id_assunto[TAM_MAX];
  int ano_eleicao;
}
Processo;

// Prototipagem funções 
void QuicksortDataAtual(Processo *processos, int inf, int sup);
void QntdProcessosID_assunto(Processo * processos);
int contarIdClasse();
void saidaID(Processo * processos, int qtdProcessos);
void QuickSortID(Processo * V, int inf, int sup);
void Swap(Processo * a, Processo * b);
int Particao(Processo * V, int inf, int sup);
int ParticaoData(Processo *processos, int inf, int sup);
void saidaData(Processo * processos, int qtdProcessos);
void contarAssuntosMultiplos(Processo *processos);
void contarDiasProcesso(Processo *processos, unsigned char *string);
Processo * nomeArquivo();
Processo * salvaremStruct(const char * nomeArquivo);

#endif