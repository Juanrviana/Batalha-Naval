#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Define o tamanho máximo possível do tabuleiro
#define MAX 30

// Declaração dos tabuleiros e variáveis globais
char tabuleiro_visivel[MAX][MAX];
char tabuleiro_gabarito[MAX][MAX];
int tamanho_tabuleiro;
int total_alvos;
int jogadas = 0;

// Função para imprimir o tabuleiro visível
void imprimir_tabuleiro(char tabuleiro[MAX][MAX]) {
printf("   ");
for (int j = 0; j < tamanho_tabuleiro; j++) {
    printf("%2d ", j);//Cabeçalho das colunas
}
printf("\n");

for (int i = 0; i < tamanho_tabuleiro; i++) {
    printf("%2d ", i); // Índice da linha
    for (int j = 0; j < tamanho_tabuleiro; j++) {
        printf("%2c ", tabuleiro[i][j]); // Célula do tabuleiro
    }
    printf("\n");
}

}

// Função para verificar se uma posição já está ocupada
int posicao_ocupada(int linha, int coluna) {
    return tabuleiro_gabarito[linha][coluna] != '0';
}
// Função para tentar colocar um barco (ou mina/submarino) no tabuleiro gabarito
int colocar_barco(int tamanho, char tipo) {
    int tentativas = 100;
    while (tentativas--) {
        int l = rand() % tamanho_tabuleiro;
        int c = rand() % tamanho_tabuleiro;
        int dir = rand() % 2; // 0 = horizontal, 1 = vertical
        int valido = 1;

        if (dir == 0) {//Direção horizontal
            if (c + tamanho > tamanho_tabuleiro) continue;
            for (int i = 0; i < tamanho; i++) {
                if (posicao_ocupada(l, c + i)) {
                    valido = 0; break;
                }
            }
            if (valido) {
                for (int i = 0; i < tamanho; i++) {
                    tabuleiro_gabarito[l][c + i] = tipo;
                    total_alvos++;
                }
                return 1;
            }
        } else {//Direção vertical
            if (l + tamanho > tamanho_tabuleiro) continue;
            for (int i = 0; i < tamanho; i++) {
                if (posicao_ocupada(l + i, c)) {
                    valido = 0; break;
                }
            }
            if (valido) {
                for (int i = 0; i < tamanho; i++) {
                    tabuleiro_gabarito[l + i][c] = tipo;
                    total_alvos++;
                }
                return 1;
            }
        }
    }
    return 0;//Se não conseguir colocar o barco
}

//Inicializa os tabuleiros e distribui os alvos de acordo com a dificuldade
void criar_tabuleiro() {
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        for (int j = 0; j < tamanho_tabuleiro; j++) {
            tabuleiro_visivel[i][j] = 'x';//Visível ao jogador
            tabuleiro_gabarito[i][j] = '0';//Gabarito oculto
        }
    }

    total_alvos = 0;

    //Distribuição de alvos conforme dificuldade
    if(tamanho_tabuleiro == 10){//Fácil
        colocar_barco(1, 'M');//Mina
        colocar_barco(2, 'N');//Navio
        colocar_barco(3, 'S');//Submarino
    } else if (tamanho_tabuleiro == 20){//Média
        colocar_barco(1, 'M');
        colocar_barco(1, 'M');
        colocar_barco(2, 'N');
        colocar_barco(2, 'N');
        colocar_barco(3, 'S');
    } else {//Difícil
        colocar_barco(1, 'M'); colocar_barco(1, 'M'); colocar_barco(1, 'M');
        colocar_barco(2, 'N'); colocar_barco(4, 'N');
        colocar_barco(3, 'S'); colocar_barco(3, 'S'); colocar_barco(3, 'S');
    }
}

// Processa uma jogada feita pelo jogador
void processar_jogada(int linha, int coluna) {
    char valor = tabuleiro_gabarito[linha][coluna];
    tabuleiro_visivel[linha][coluna] = valor;

    if (valor != '0') total_alvos--; //se acertou um alvo
    jogadas++;//Incrementa o número de jogadas
    
    imprimir_tabuleiro(tabuleiro_visivel);
    printf("\nVocê acertou: %c\n", valor);
}

// Função principal de jogo onde o jogador fornece coordenadas
void jogar() {
    int linha, coluna;
    char entrada[10];

    while (total_alvos > 0) {
        printf("\nDigite uma coordenada (linha,coluna): ");
        scanf("%s", entrada);
        sscanf(entrada, "%d,%d", &linha, &coluna);

        //verifica se a coordenada está dentro dos limites
        if (linha < 0 || linha >= tamanho_tabuleiro || coluna < 0 || coluna >= tamanho_tabuleiro) {
            printf("Coordenada inválida. Tente novamente.\n");
            continue;
        }

        //Verifica se a posição já foi jogada
        if (tabuleiro_visivel[linha][coluna] != 'x') {
            printf("Você já jogou nessa posição.\n");
            continue;
        }

        processar_jogada(linha, coluna);
    }
    printf("\nParabéns! Você venceu em %d jogadas.\n", jogadas);
}

// Função para escolher a dificuldade
void escolher_dificuldade() {
    int escolha;
    printf("Escolha a dificuldade:\n1 - Fácil\n2 - Médio\n3 - Difícil\nDigite sua opção: ");
    if(scanf("%d", &escolha) != 1){
        printf("Entrada inválida.\n");
        exit(1); //encera o programa se for entrada inválida
    }
    switch (escolha) {
        case 1:
            tamanho_tabuleiro = 10;
             break;
        case 2:
            tamanho_tabuleiro = 20;
            break;
        case 3:
            tamanho_tabuleiro = 30;
            break;      
        default:
            printf("Opção inválida. Tente novamente.\n");
            exit(1); //encerra o programa para escolhas erradas
    }
}

//Pergunta ao jogador se deseja jogar novamente
int reiniciar(){
    char opcao;
    printf("\nDeseja jogar novamente? (s/n): ");
    scanf(" %c", &opcao);
    return opcao == 's' || opcao == 'S';
}

//Função principal
int main() {
    srand(time(NULL)); // Semente aleatória

   do{ 
        escolher_dificuldade();      //define o tamanho do tabuleiro
        criar_tabuleiro();          //prepara o campo de batalha
        imprimir_tabuleiro(tabuleiro_visivel);//mostra o tabuleiro ao jogador
        jogar();                   //inicia a rodada do jogo
    }  while(reiniciar());        //pergunta se o jogador quer jogar novamente
    
   return 0;
}