#include <stdio.h>
#include <string.h>

int main() {
    int M, L, C;
    
    while (scanf("%d %d %d", &M, &L, &C) != EOF) {
        // Ler as M palavras
        char palavras[M][71]; // cada palavra tem no máximo C (≤70) caracteres + '\0'
        
        for (int i = 0; i < M; i++) {
            scanf("%s", palavras[i]);
        }
        
        int linhas = 1;  // pelo menos 1 linha
        int chars_na_linha = 0;
        int paginas = 0;
        
        for (int i = 0; i < M; i++) {
            int tamanho_palavra = strlen(palavras[i]);
            
            // Se é a primeira palavra da linha
            if (chars_na_linha == 0) {
                if (tamanho_palavra <= C) {
                    chars_na_linha = tamanho_palavra;
                }
            } 
            // Se já tem palavra na linha, verificar se cabe mais uma (com espaço)
            else {
                if (chars_na_linha + 1 + tamanho_palavra <= C) {
                    chars_na_linha += 1 + tamanho_palavra; // espaço + palavra
                } else {
                    // Nova linha
                    linhas++;
                    chars_na_linha = tamanho_palavra;
                }
            }
        }
        
        // Calcular número de páginas
        paginas = (linhas + L - 1) / L; // teto(linhas / L)
        
        printf("%d\n", paginas);
    }
    
    return 0;
}