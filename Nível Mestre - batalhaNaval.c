#include <stdio.h>

#define TAM 10       // tamanho do tabuleiro (10x10)
#define TAM_HAB 5    // tamanho das matrizes de habilidades (5x5)

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializando o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionando navios (valor 3) — exemplo simples
    // Navio horizontal
    for (int j = 2; j < 5; j++) {
        tabuleiro[2][j] = 3;
    }
    // Navio vertical
    for (int i = 5; i < 8; i++) {
        tabuleiro[i][7] = 3;
    }

    // Criando matrizes de habilidades (cone, cruz, octaedro)
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    // Habilidade: CONE (origem no topo e se expandindo para baixo)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // A base do cone cresce conforme a linha aumenta
            if (j >= TAM_HAB/2 - i && j <= TAM_HAB/2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // Habilidade: CRUZ (origem no centro)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB/2 || j == TAM_HAB/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // Habilidade: OCTAEDRO (formato de losango, origem no centro)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // A distância do centro define se a célula faz parte da forma
            if ( (i + j >= TAM_HAB/2) && (i + j <= TAM_HAB - 1 + TAM_HAB/2) &&
                 (i - j <= TAM_HAB/2) && (j - i <= TAM_HAB/2))
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // Definindo posições de origem das habilidades no tabuleiro
    int origemConeLinha = 0, origemConeColuna = 0;    // canto superior esquerdo
    int origemCruzLinha = 4, origemCruzColuna = 3;    // centro aproximado
    int origemOctaLinha = 6, origemOctaColuna = 4;    // parte inferior do tabuleiro

    // Função para sobrepor habilidades (usando valor 5 no tabuleiro)
    // Cone
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = origemConeLinha + i;
            int coluna = origemConeColuna + j;
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (cone[i][j] == 1 && tabuleiro[linha][coluna] == 0)
                    tabuleiro[linha][coluna] = 5;
            }
        }
    }

    // Cruz
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = origemCruzLinha - TAM_HAB/2 + i;
            int coluna = origemCruzColuna - TAM_HAB/2 + j;
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (cruz[i][j] == 1 && tabuleiro[linha][coluna] == 0)
                    tabuleiro[linha][coluna] = 5;
            }
        }
    }

    // Octaedro
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = origemOctaLinha - TAM_HAB/2 + i;
            int coluna = origemOctaColuna - TAM_HAB/2 + j;
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (octaedro[i][j] == 1 && tabuleiro[linha][coluna] == 0)
                    tabuleiro[linha][coluna] = 5;
            }
        }
    }

    // Exibindo o tabuleiro completo
    printf("\n=== TABULEIRO COM HABILIDADES ESPECIAIS ===\n\n");
    printf("Legenda: 0 = água | 3 = navio | 5 = área de habilidade\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
