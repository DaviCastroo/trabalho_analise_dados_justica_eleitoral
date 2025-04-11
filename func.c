#include "func.h"

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>


void Swap(Processo * a, Processo * b) {
  Processo temp = * a;
  * a = * b;
  * b = temp;
}

int ParticaoID(Processo * V, int inf, int sup) {
  Processo Pivo = V[(inf + sup) / 2];
  int i = inf;
  int j = sup;

  while (i <= j) {
    while (strcmp(V[i].id, Pivo.id) < 0) i++;
    while (strcmp(V[j].id, Pivo.id) > 0) j--;
    if (i <= j) {
      Swap( & V[i], & V[j]);
      i++;
      j--;
    }
  }
  return i;
}
// QuickSort crescente por ID
void QuickSortID(Processo * V, int inf, int sup) {
  if (inf < sup) {
    int P = ParticaoID(V, inf, sup);
    QuickSortID(V, inf, P - 1);
    QuickSortID(V, P, sup);
  }
}

// Ordena por data (mais recente para mais antiga)
void QuicksortDataAtual(Processo * processos, int inf, int sup) {
  if (inf < sup) {
    int P = ParticaoData(processos, inf, sup);
    QuicksortDataAtual(processos, inf, P - 1);
    QuicksortDataAtual(processos, P, sup);
  }
}

// Faz a comparação das datas, de forma decrescente 
int ParticaoData(Processo * processos, int inf, int sup) {
  Processo Pivo = processos[(inf + sup) / 2];
  int i = inf;
  int j = sup;
  while (i <= j) {
    while (strcmp(processos[i].data_ajuizamento, Pivo.data_ajuizamento) > 0) i++;
    while (strcmp(processos[j].data_ajuizamento, Pivo.data_ajuizamento) < 0) j--;
    if (i <= j) {
      Swap( & processos[i], & processos[j]);
      i++;
      j--;
    }
  }
  return i;
}

void saidaID(Processo * processos, int qtdProcessos) {
  FILE * saida = fopen("ordenado_por_id.csv", "w");
  if (!saida) {
    printf("Erro ao criar o arquivo de saída.\n");
    free(processos);
    return;
  }

  fprintf(saida, "\"id\",\"numero\",\"data_ajuizamento\",\"id_classe\",\"id_assunto\",\"ano_eleicao\"\n");

  for (int i = 0; i < qtdProcessos; i++) {
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
}

void saidaData(Processo * processos, int qtdProcessos) {
  FILE * saida = fopen("ordenado_por_data.csv", "w");
  if (!saida) {
    printf("Erro ao criar o arquivo de saída.\n");
    free(processos);
    return;
  }

  fprintf(saida, "\"id\",\"numero\",\"data_ajuizamento\",\"id_classe\",\"id_assunto\",\"ano_eleicao\"\n");

  for (int i = 0; i < qtdProcessos; i++) {
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
  printf("Arquivo 'ordenado_por_data.csv' gerado com sucesso.\n");
}

int contarIdClasse(Processo * processos, unsigned char * string) {
  int processosnaClasse = 0;
  for (int i = 0; i < NumProcesso; i++) {
    if (strstr(processos[i].id_classe, string) != NULL)
      processosnaClasse++;
  }
  printf("Ha %d processos ligados a classe '%s'.\n", processosnaClasse, string);
}

void QntdProcessosID_assunto(Processo * processos) {
  int Qtd_total = 0;
  for (int i = 0; i < NumProcesso; i++) {
    Qtd_total++;
    for (int j = 0; processos[i].id_assunto[j] != '\0'; j++) {
      if (processos[i].id_assunto[j] == ',')
        Qtd_total++;
    }
  }

  int assuntos_diff[100]; // Assuntos únicos
  int Qtd_diff = 0;
  for (int i = 0; i < NumProcesso; i++) {
    int temp[5] = {
      0
    };
    int Qtd_adicionado = sscanf(processos[i].id_assunto, "%d,%d,%d,%d,%d", &
      temp[0], & temp[1], & temp[2], &
      temp[3], & temp[4]);

    for (int j = 0; j < Qtd_adicionado; j++) {
      int valor = temp[j];
      int ja_existe = 0;
      for (int k = 0; k < Qtd_diff; k++) {
        if (assuntos_diff[k] == valor) {
          ja_existe = 1;
          break;
        }
      }
      if (!ja_existe) {
        assuntos_diff[Qtd_diff++] = valor;
      }
    }
  }
  printf("Constam %d assuntos totais na base de dados e %d assuntos unicos.\\n", Qtd_total, Qtd_diff);
}

// Exibe os processos que têm múltiplos assuntos (separados por vírgula)
void contarAssuntosMultiplos(Processo * processos) {
  int Qtd_total = 0;
  for (int i = 0; i < NumProcesso; i++) {
    if (strstr(processos[i].id_assunto, ",") != NULL) {
      printf("%s,%s,%s,{%s},\"{%s}\",%d\n",
        processos[i].id, processos[i].numero, processos[i].data_ajuizamento,
        processos[i].id_classe, processos[i].id_assunto, processos[i].ano_eleicao);
      Qtd_total++;
    }
  }
  printf("\n No arquivo existem %d processos que estao vinculados a mais de um assunto.\n", Qtd_total);
}

// Calcula quantos dias se passaram desde a data de ajuizamento até hoje
void contarDiasProcesso(Processo * processos, unsigned char * string) {
  time_t calendario_atual;
  if (time( & calendario_atual) == -1) {
    printf("Calendario indisponível.\n");
    exit(1);
  }
  struct tm * calendario_atual_struct = localtime( & calendario_atual);
  struct tm data_CSV;

  int i;
  for (i = 0; i < NumProcesso; i++) {
    if (strstr(processos[i].id, string) != NULL)
      break;
  }

  if (i == NumProcesso) {
    printf("Processo com ID '%s' não encontrado.\\n", string);
    return;
  }

  if (sscanf(processos[i].data_ajuizamento, "%d-%d-%d %d:%d:%d", &
      data_CSV.tm_year, & data_CSV.tm_mon, & data_CSV.tm_mday, &
      data_CSV.tm_hour, & data_CSV.tm_min, & data_CSV.tm_sec) == 6) {
    data_CSV.tm_year -= 1900;
    data_CSV.tm_mon -= 1;
    data_CSV.tm_isdst = -1;
  } else {
    printf("Erro ao ler a data do processo.\\n");
    return;
  }

  time_t tempo_CSV = mktime( & data_CSV);

  if (tempo_CSV == -1) {
    printf("\\nErro ao converter a data CSV para time_t\\n");
    exit(1);
  }

  time_t segundos_diferenca = difftime(calendario_atual, tempo_CSV);
  float dias = (float) segundos_diferenca / 86400;
  if (calendario_atual_struct -> tm_hour > data_CSV.tm_hour)
    dias--;

  printf("\\nO processo de id '%s' esta em tramitacao na justica ha %.f dias!\\n", string, dias);
}

// lê e guarda os dados em um struct // 
Processo * salvaremStruct(const char * nomeArquivo) {
  int N = 0;
  char linha[2048];

  FILE * arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL) {
    printf("ERRO! Falha ao abrir o arquivo.\n");
    return NULL;
  }

  Processo * processos = (Processo * ) malloc(NumProcesso * sizeof(Processo));
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

    char * token;
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
      case 0:
        strncpy(processos[N].id, valor, TAM_MAX);
        break;
      case 1:
        strncpy(processos[N].numero, valor, TAM_MAX);
        break;
      case 2:
        strncpy(processos[N].data_ajuizamento, valor, TAM_MAX);
        break;
      case 3:
        strncpy(processos[N].id_classe, valor, TAM_MAX);
        break;
      case 4:
        strncpy(processos[N].id_assunto, valor, TAM_MAX);
        break;
      case 5:
        processos[N].ano_eleicao = atoi(valor);
        break;
      }

      campo++;
    }

    N++;
  }

  fclose(arquivo);
  return processos;
}

// lê o nome do arquivo a ser consultado
Processo * nomeArquivo() {
  char nome_arquivo[256];

  printf("Digite o nome do arquivo CSV (Exemplo: arquivo.csv): ");
  scanf("%255s", nome_arquivo);

  Processo * processos = salvaremStruct(nome_arquivo);
}