#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    // 1. Inicializando o tabuleiro com água (0)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // 2. Declarando navios (horizontal e vertical), cada um com tamanho 3
    int navio_horizontal[TAM_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
    int navio_vertical[TAM_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};

    // 3. Coordenadas iniciais fixas definidas no código
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // 4. Posicionando o navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        // Validação: dentro dos limites
        if ((coluna_horizontal + i) < TAM_TABULEIRO) {
            // Verificação de sobreposição
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] == VALOR_AGUA) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
            }
        }
    }

    // 5. Posicionando o navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        if ((linha_vertical + i) < TAM_TABULEIRO) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == VALOR_AGUA) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
            }
        }
    }

    // 6. Exibindo o tabuleiro completo
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}