# 📊 Análise de Dados da Justiça Eleitoral

Este projeto em linguagem C realiza a análise de um conjunto de dados da Justiça Eleitoral, permitindo ao usuário visualizar, ordenar e extrair estatísticas de processos judiciais relacionados a eleições.

---

## 🧩 Estrutura do Projeto

O projeto é modularizado em três arquivos principais:

📁 `main.c` – Ponto de entrada do programa com menu interativo  
📁 `func.c` – Implementações das funções auxiliares  
📁 `func.h` – Definições, estrutura de dados e protótipos de funções

---

## 🔍 Funcionalidades

O programa oferece as seguintes opções no menu:

```
===== MENU INTERATIVO =====
1. Ordenar por ID (ordem crescente)
2. Ordenar por data de ajuizamento (Mais recente ao mais antigo)
3. Contar processos por ID de classe
4. Contar assuntos totais e únicos
5. Listar processos com múltiplos assuntos
6. Dias de tramitação de um processo
0. Sair
```

---

## 🏗️ Como Compilar

Use o compilador `gcc` para compilar o projeto:

```bash
gcc main.c func.c -o analise_processos
```

---

## ▶️ Como Executar

Após a compilação, execute o programa com:

```bash
./analise_processos
```


## 📄 Licença

Projeto feito com foco em uso acadêmico




