#include <stdio.h>

int main() {
    // Definindo tamanho fixo do tabuleiro (10x10)
    const int TAM = 10;

    // Definindo o tamanho fixo dos navios (3 posições)
    const int TAM_NAVIO = 3;

    // Matriz que representa o tabuleiro
    int tabuleiro[TAM][TAM];

    // Variáveis para coordenadas iniciais dos navios
    int linhaNavioH = 2; // linha inicial do navio horizontal
    int colunaNavioH = 1; // coluna inicial do navio horizontal

    int linhaNavioV = 5; // linha inicial do navio vertical
    int colunaNavioV = 7; // coluna inicial do navio vertical

    //  Inicializando o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    //  Posicionando o navio horizontal (valor 3)
    // Verificação: garante que o navio cabe dentro do tabuleiro
    if (colunaNavioH + TAM_NAVIO <= TAM) {
        for (int j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linhaNavioH][colunaNavioH + j] = 3;
        }
    } else {
        printf("Erro: o navio horizontal ultrapassa os limites do tabuleiro!\n");
        return 1;
    }

    //  Posicionando o navio vertical (valor 3)
    // Verificação: garante que o navio cabe e não se sobrepõe
    if (linhaNavioV + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            // Validação simples pra não sobrepor outro navio
            if (tabuleiro[linhaNavioV + i][colunaNavioV] == 3) {
                printf("Erro: os navios se sobrepõem!\n");
                return 1;
            }
            tabuleiro[linhaNavioV + i][colunaNavioV] = 3;
        }
    } else {
        printf("Erro: o navio vertical ultrapassa os limites do tabuleiro!\n");
        return 1;
    }

    //  Exibindo o tabuleiro completo
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
