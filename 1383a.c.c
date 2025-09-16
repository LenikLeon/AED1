#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verificarGrupo(int grupo[9]) {
    int contador[10] = {0};
    
    for (int i = 0; i < 9; i++) {
        if (grupo[i] < 1 || grupo[i] > 9) {
            return false;
        }
        contador[grupo[i]]++;
    }
    
    for (int i = 1; i <= 9; i++) {
        if (contador[i] != 1) {
            return false;
        }
    }
    
    return true;
}

bool verificarSudoku(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        if (!verificarGrupo(sudoku[i])) {
            return false;
        }
    }
    
    for (int j = 0; j < 9; j++) {
        int coluna[9];
        for (int i = 0; i < 9; i++) {
            coluna[i] = sudoku[i][j];
        }
        if (!verificarGrupo(coluna)) {
            return false;
        }
    }
    
    for (int regiao_i = 0; regiao_i < 9; regiao_i += 3) {
        for (int regiao_j = 0; regiao_j < 9; regiao_j += 3) {
            int regiao[9];
            int idx = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    regiao[idx++] = sudoku[regiao_i + i][regiao_j + j];
                }
            }
            if (!verificarGrupo(regiao)) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int instance = 1; instance <= n; instance++) {
        int sudoku[9][9];
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }
        
        bool valido = verificarSudoku(sudoku);
        
        printf("Instancia %d\n", instance);
        printf(valido ? "SIM\n" : "NAO\n");
        printf("\n");
    }
    
    return 0;
}