📊 Análise de Dados da Justiça Eleitoral
Este projeto em linguagem C realiza a análise de um conjunto de dados da Justiça Eleitoral, permitindo ao usuário visualizar, ordenar e extrair estatísticas de processos judiciais relacionados a eleições.

🧩 Estrutura do Projeto
O projeto é modularizado em três arquivos principais:

main.c: ponto de entrada do programa com menu interativo.

func.c: implementações das funções auxiliares.

func.h: definições, estrutura de dados e protótipos de funções.

🔍 Funcionalidades
O programa oferece as seguintes opções no menu:

Ordenar por ID: ordena os processos de forma crescente pelo ID.

Ordenar por data de ajuizamento: ordena os processos da data mais recente para a mais antiga.

Contar processos por ID de classe: permite ao usuário digitar um ID de classe e retorna o número de processos correspondentes.

Contar assuntos totais e únicos: apresenta a quantidade de assuntos diferentes tratados nos processos.

Listar processos com múltiplos assuntos: identifica e lista os processos que envolvem mais de um assunto.

Calcular dias de tramitação de um processo: informa o tempo de tramitação de um processo específico a partir de sua data de ajuizamento.

🏗️ Como Compilar
Você pode compilar o projeto usando gcc:

bash
Copiar
Editar
gcc main.c func.c -o analise_processos
▶️ Como Executar
Após a compilação:

bash
Copiar
Editar
./analise_processos
📁 Entrada Esperada
O programa lê os dados de um arquivo CSV de processos judiciais, que deve conter os seguintes campos por linha:

ID do processo

Número

Data de ajuizamento

ID da classe

ID do assunto

Ano da eleição

O caminho e formato exato do arquivo podem ser ajustados na função nomeArquivo().

✍️ Autoria
Este projeto foi desenvolvido como trabalho acadêmico para análise de dados judiciais com foco na Justiça Eleitoral.
