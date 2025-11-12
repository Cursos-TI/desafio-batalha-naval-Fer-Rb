#include <stdio.h>

int main() {
    // Definições básicas
    const int TAM = 10;        // tamanho do tabuleiro
    const int TAM_NAVIO = 3;   // tamanho fixo de cada navio

    // Matriz 10x10 representando o tabuleiro (0 = água, 3 = navio)
    int tabuleiro[TAM][TAM];

    // Inicializando o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais dos navios
    // Dois navios horizontais/verticais
    int linhaNavioH = 1, colunaNavioH = 2;  // navio horizontal
    int linhaNavioV = 4, colunaNavioV = 7;  // navio vertical

    // Dois navios diagonais
    int linhaDiag1 = 6, colunaDiag1 = 1;    // diagonal ↘ (linha e coluna aumentam)
    int linhaDiag2 = 2, colunaDiag2 = 8;    // diagonal ↙ (linha aumenta, coluna diminui)

    // Função simples de validação e posicionamento — feita diretamente no código

    // Navio Horizontal
    if (colunaNavioH + TAM_NAVIO <= TAM) {
        for (int j = 0; j < TAM_NAVIO; j++) {
            if (tabuleiro[linhaNavioH][colunaNavioH + j] == 3) {
                printf("Erro: sobreposição detectada no navio horizontal!\n");
                return 1;
            }
            tabuleiro[linhaNavioH][colunaNavioH + j] = 3;
        }
    } else {
        printf("Erro: navio horizontal ultrapassa os limites do tabuleiro!\n");
        return 1;
    }

    // Navio Vertical
    if (linhaNavioV + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaNavioV + i][colunaNavioV] == 3) {
                printf("Erro: sobreposição detectada no navio vertical!\n");
                return 1;
            }
            tabuleiro[linhaNavioV + i][colunaNavioV] = 3;
        }
    } else {
        printf("Erro: navio vertical ultrapassa os limites do tabuleiro!\n");
        return 1;
    }

    // Navio Diagonal ↘ (linha++ e coluna++)
    if (linhaDiag1 + TAM_NAVIO <= TAM && colunaDiag1 + TAM_NAVIO <= TAM) {
        for (int k = 0; k < TAM_NAVIO; k++) {
            if (tabuleiro[linhaDiag1 + k][colunaDiag1 + k] == 3) {
                printf("Erro: sobreposição detectada na diagonal ↘!\n");
                return 1;
            }
            tabuleiro[linhaDiag1 + k][colunaDiag1 + k] = 3;
        }
    } else {
        printf("Erro: navio diagonal ↘ ultrapassa os limites do tabuleiro!\n");
        return 1;
    }

    // Navio Diagonal ↙ (linha++ e coluna--)
    if (linhaDiag2 + TAM_NAVIO <= TAM && colunaDiag2 - (TAM_NAVIO - 1) >= 0) {
        for (int k = 0; k < TAM_NAVIO; k++) {
            if (tabuleiro[linhaDiag2 + k][colunaDiag2 - k] == 3) {
                printf("Erro: sobreposição detectada na diagonal ↙!\n");
                return 1;
            }
            tabuleiro[linhaDiag2 + k][colunaDiag2 - k] = 3;
        }
    } else {
        printf("Erro: navio diagonal ↙ ultrapassa os limites do tabuleiro!\n");
        return 1;
    }

    // Exibição do tabuleiro
    printf("\n=== TABULEIRO COMPLETO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
