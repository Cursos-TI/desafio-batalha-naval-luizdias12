#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

void navioDiagonal(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna) {
    if(linha + 2 >= LINHAS || coluna + 2 >= COLUNAS) {
        printf("Fora da area do tabuleiro!\n");
        return;
    }

    if(tabuleiro[linha][coluna] != 0 || 
        tabuleiro[linha + 1][coluna + 1] != 0 ||
        tabuleiro[linha + 2][coluna + 2] != 0) {
        printf("Posicao ja esta ocupada!\n");
        return;
    }

    tabuleiro[linha][coluna] = 3;
    tabuleiro[linha + 1][coluna + 1] = 3;
    tabuleiro[linha + 2][coluna + 2] = 3;
}

int main() {

    int tabuleiro[LINHAS][COLUNAS];

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    for (int h = 5; h <= 7; h++) {
        tabuleiro[3][h] = 3;
    }

    for (int v = 5; v <= 7; v++) {
        tabuleiro[v][2] = 3;
    }

    navioDiagonal(tabuleiro, 1, 1);
    navioDiagonal(tabuleiro, 6, 5);

    printf("TABULEIRO BATALHA NAVAL\n");
    printf("   ");
    for (int b = 0; b < LINHAS; b++) {
        printf("%c ", 'A' + b);
    }
    printf("\n");

    for (int c = 0; c < LINHAS; c++) {
        if (c < 9) printf(" ");
        printf("%d ", c + 1);
        for (int d = 0; d < COLUNAS; d++) {
            printf("%d ", tabuleiro[c][d]);
        }
        printf("\n");
    }
    
     
    return 0;
}