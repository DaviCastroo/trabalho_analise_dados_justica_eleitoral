# 📊 Análise de Dados da Justiça Eleitoral

Este projeto em linguagem C realiza a análise de um conjunto de dados da Justiça Eleitoral, permitindo ao usuário visualizar, ordenar e extrair estatísticas de processos judiciais relacionados a eleições.

## 🧩 Estrutura do Projeto

O projeto é modularizado em três arquivos principais:

- `main.c`: ponto de entrada do programa com menu interativo.
- `func.c`: implementações das funções auxiliares.
- `func.h`: definições, estrutura de dados e protótipos de funções.

## 🔍 Funcionalidades

O programa oferece as seguintes opções no menu:

```text
===== MENU INTERATIVO =====
1. Ordenar por ID (ordem crescente)
2. Ordenar por data de ajuizamento (Mais recente ao mais antigo)
3. Contar processos por ID de classe
4. Contar assuntos totais e únicos
5. Listar processos com múltiplos assuntos
6. Dias de tramitação de um processo
0. Sair
```

## 🏗️ Como Compilar

Você pode compilar o projeto usando `gcc`:

```bash
gcc main.c func.c -o analise_processos
```

## ▶️ Como Executar

Após a compilação:

```bash
./analise_processos
```

## 🗃️ Formato do Arquivo de Entrada (CSV)

O programa espera um arquivo `.csv` com os seguintes campos em cada linha (sem cabeçalho):

```csv
id,numero,data_ajuizamento,id_classe,id_assunto,ano_eleicao
```

Exemplo:

```csv
PRC1234,0000001,2018-06-12,CL001,AS045,2018
PRC5678,0000002,2020-02-20,CL002,AS045,2020
```

O arquivo deve conter exatamente **18392 processos**, conforme definido na constante `NumProcesso`.

O caminho e nome do arquivo são definidos na função `nomeArquivo()` no código. Por padrão, o programa pede o nome do arquivo ao usuário.

## 🤝 Contribuições

Contribuições são bem-vindas! Se quiser melhorar o projeto, sugerir novas análises ou refatorar o código:

1. Faça um fork do repositório
2. Crie uma branch: `git checkout -b minha-melhoria`
3. Commit suas alterações: `git commit -m 'melhoria'`
4. Push para a branch: `git push origin minha-melhoria`
5. Abra um Pull Request

## 📄 Licença

Este projeto é de uso acadêmico. Para outros fins, consulte o autor.

## 🙋‍♂️ Autor

Seu Nome  
[Seu GitHub](https://github.com/seuusuario)  
[LinkedIn (opcional)](https://linkedin.com/in/seulink)
