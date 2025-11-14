#include <stdio.h>

#define TAM 10          // Tamanho do tabuleiro (10x10)
#define NAVIO_TAM 3     // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM];  // Matriz que representa o tabuleiro
    int i, j;

    // -------------------------------
    // 1. Inicializar o tabuleiro com 0
    // -------------------------------
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;  // 0 = água
        }
    }

    // --------------------------------------------------
    // 2. Definição dos navios (valor 3 significa “navio”)
    // --------------------------------------------------
    int navioHorizontal[NAVIO_TAM] = {3, 3, 3};
    int navioVertical[NAVIO_TAM]   = {3, 3, 3};

    // ---------------------------------------------------------
    // 3. Definição das posições iniciais (fixas neste exercício)
    //    OBS: podem ser alteradas livremente, desde que válidas
    // ---------------------------------------------------------
    int inicioH_L = 4;   // linha do navio horizontal
    int inicioH_C = 2;   // coluna inicial do navio horizontal

    int inicioV_L = 1;   // linha inicial do navio vertical
    int inicioV_C = 7;   // coluna do navio vertical

    // ---------------------------------------------------------
    // 4. Validação de limites do tabuleiro
    // ---------------------------------------------------------
    if (inicioH_C + NAVIO_TAM > TAM) {
        printf("ERRO: Navio horizontal ultrapassa os limites!\n");
        return 1;
    }
    if (inicioV_L + NAVIO_TAM > TAM) {
        printf("ERRO: Navio vertical ultrapassa os limites!\n");
        return 1;
    }

    // ---------------------------------------------------------
    // 5. Validação de sobreposição entre navios
    // ---------------------------------------------------------
    for (i = 0; i < NAVIO_TAM; i++) {
        // Verifica horizontal contra vertical
        if ((inicioH_L == inicioV_L + i) &&
            (inicioH_C <= inicioV_C && inicioV_C <= inicioH_C + (NAVIO_TAM - 1))) {
            printf("ERRO: Navios se sobrepoem!\n");
            return 1;
        }
    }

    // ---------------------------------------------------------
    // 6. Posicionamento do navio horizontal no tabuleiro
    // ---------------------------------------------------------
    for (i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[inicioH_L][inicioH_C + i] = navioHorizontal[i];
    }

    // ---------------------------------------------------------
    // 7. Posicionamento do navio vertical no tabuleiro
    // ---------------------------------------------------------
    for (i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[inicioV_L + i][inicioV_C] = navioVertical[i];
    }

    // ---------------------------------------------------------
    // 8. Exibição do tabuleiro
    // ---------------------------------------------------------
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
