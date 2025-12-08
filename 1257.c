#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    
    for (int caso = 0; caso < N; caso++) {
        int L;
        scanf("%d", &L);
        
        int hash_total = 0;
        
        for (int linha = 0; linha < L; linha++) {
            char string[51];
            scanf("%s", string);
            
            int len = strlen(string);
            for (int pos = 0; pos < len; pos++) {
                int valor_alfabeto = string[pos] - 'A';
                int valor = valor_alfabeto + linha + pos;
                hash_total += valor;
            }
        }
        
        printf("%d\n", hash_total);
    }
    
    return 0;
}