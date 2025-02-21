#include <stdio.h>

#define TAMANHO 10

void navioDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if(linha + 2 >= TAMANHO || coluna + 2 >= TAMANHO) {
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

void desenharCone(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if(linha < 0 || linha + 2 >= TAMANHO || coluna - 1 < 0 || coluna + 1 >= TAMANHO) {
        printf("Cone - Fora da area do tabuleiro!\n");
        return;
    }
    // topo do cone
    tabuleiro[linha][coluna] = 1;
    // meio do cone
    tabuleiro[linha + 1][coluna - 1] = 1;
    tabuleiro[linha + 1][coluna] = 1;
    tabuleiro[linha + 1][coluna + 1] = 1;
    //base do cone
    for (int j = coluna - 2; j <= coluna + 2; j++) {
        if(j > 0 && j < TAMANHO) {
            tabuleiro[linha + 2][j] = 1;
        }
    }
}

void desenharCruz(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha < 0 || linha + 2 >= TAMANHO || 
        coluna - 2 < 0 || coluna + 2 >= TAMANHO) {
        printf("Cruz - Fora da area do tabuleiro!\n");
        return;
    }

    // linha horizontal da cruz
    for (int j = coluna - 2; j <= coluna + 2; j++) {
        tabuleiro[linha + 1][j] = 1;
    }

    // linha vertical da cruz
    for (int i = linha; i <= linha + 2; i++ ) {
        tabuleiro[i][coluna] = 1;
    }
}

void desenharOctaedro(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha < 0 || linha + 2 >= TAMANHO || 
        coluna - 1 < 0 || coluna + 1 >= TAMANHO) {
        printf("Octaedro - Fora da area do tabuleiro!\n");
        return;
    }

    // topo do octaedro
    tabuleiro[linha][coluna] = 1;
    // meio do octaedro
    tabuleiro[linha + 1][coluna - 1] = 1;
    tabuleiro[linha + 1][coluna] = 1;
    tabuleiro[linha + 1][coluna + 1] = 1;
    // base do octaedro
    tabuleiro[linha + 2][coluna] = 1;

}

int main() {

    int tabuleiro[TAMANHO][TAMANHO];

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }


    desenharCone(tabuleiro, 2, 4);
    desenharCruz(tabuleiro, 0, 2);
    desenharOctaedro(tabuleiro, 6, 5);

    printf("TABULEIRO BATALHA NAVAL\n");
    printf("   ");
    for (int b = 0; b < TAMANHO; b++) {
        printf("%c ", 'A' + b);
    }
    printf("\n");

    for (int c = 0; c < TAMANHO; c++) {
        if (c < 9) printf(" ");
        printf("%d ", c + 1);
        for (int d = 0; d < TAMANHO; d++) {
            printf("%d ", tabuleiro[c][d]);
        }
        printf("\n");
    }
    
     
    return 0;
}