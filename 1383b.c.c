#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verificarLinha(int **matriz, int linha) {
    bool encontrado[10] = {false};
    for (int j = 0; j < 9; j++) {
        int num = matriz[linha][j];
        if (num < 1 || num > 9 || encontrado[num]) {
            return false;
        }
        encontrado[num] = true;
    }
    return true;
}

bool verificarColuna(int **matriz, int coluna) {
    bool encontrado[10] = {false};
    for (int i = 0; i < 9; i++) {
        int num = matriz[i][coluna];
        if (num < 1 || num > 9 || encontrado[num]) {
            return false;
        }
        encontrado[num] = true;
    }
    return true;
}

bool verificarBloco(int **matriz, int inicioLinha, int inicioColuna) {
    bool encontrado[10] = {false};
    for (int i = inicioLinha; i < inicioLinha + 3; i++) {
        for (int j = inicioColuna; j < inicioColuna + 3; j++) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || encontrado[num]) {
                return false;
            }
            encontrado[num] = true;
        }
    }
    return true;
}

bool ehSolucao(int **matriz) {
    for (int i = 0; i < 9; i++) {
        if (!verificarLinha(matriz, i)) {
            return false;
        }
    }
    for (int j = 0; j < 9; j++) {
        if (!verificarColuna(matriz, j)) {
            return false;
        }
    }
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            if (!verificarBloco(matriz, i, j)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int k = 1; k <= n; k++) {
        // Alocação dinâmica para a matriz 9x9
        int **matriz = (int **)malloc(9 * sizeof(int *));
        for (int i = 0; i < 9; i++) {
            matriz[i] = (int *)malloc(9 * sizeof(int));
        }
        
        // Leitura da matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        
        printf("Instancia %d\n", k);
        if (ehSolucao(matriz)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
        
        // Liberação da memória alocada
        for (int i = 0; i < 9; i++) {
            free(matriz[i]);
        }
        free(matriz);
    }
    
    return 0;
}