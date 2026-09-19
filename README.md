# ⚓ Batalha Naval CLI (C Language)

Projeto desenvolvido como trabalho prático da disciplina de **Algoritmos e Estruturas de Dados 1 (AED1)** na **Universidade Federal do Amazonas (UFAM)**. O software consiste na implementação do clássico jogo **Batalha Naval** em linguagem C pura, rodando via Interface de Linha de Comando (CLI).

---

## 📌 Principais Aprendizados e Conceitos Aplicados

- **Matrizes Bidimensionais e Estrutura de Dados:** Representação do campo de batalha através de matrizes $N \times N$, gerenciando o estado visível ao jogador e o gabarito oculto da partida.
- **Algoritmos de Posicionamento e Checagem de Colisão:** Lógica aleatória para posicionamento de embarcações (minas, navios e submarinos) de tamanhos dinâmicos nas orientações horizontal e vertical, garantindo que não haja sobreposição e nem extrapolação dos limites da matriz.
- **Validação de Entrada e Bounds Checking:** Tratamento de coordenadas inseridas pelo usuário via entrada formatada (`sscanf`) e prevenção de acessos fora dos limites do vetor.
- **Modularização de Código:** Organização em funções reutilizáveis e separação clara da lógica de inicialização, controle de fluxo e renderização do tabuleiro no terminal.

---

## 🛠️ Tecnologias Utilizadas

- **Linguagem:** C (padrão C99 / C11)
- **Bibliotecas Padrão:** `<stdio.h>`, `<stdlib.h>`, `<time.h>`, `<string.h>`
- **Compilador Recomendado:** GCC / Clang

---

## 🎮 Como Funciona o Jogo

O jogo possui 3 níveis de dificuldade que alteram a dimensão do tabuleiro e a quantidade de alvos:

| Dificuldade | Tamanho do Tabuleiro | Tipos de Embarcações |
| :--- | :--- | :--- |
| **Fácil** | $10 \times 10$ | 1 Mina (M), 1 Navio (N), 1 Submarino (S) |
| **Médio** | $20 \times 20$ | 2 Minas (M), 2 Navios (N), 1 Submarino (S) |
| **Difícil** | $30 \times 30$ | 3 Minas (M), 2 Navios (N), 3 Submarinos (S) |

---

## 🚀 Como Executar

1. **Clone este repositório:**
   ```bash
   git clone [https://github.com/seu-usuario/batalha-naval-c.git](https://github.com/seu-usuario/batalha-naval-c.git)
   cd batalha-naval-c
