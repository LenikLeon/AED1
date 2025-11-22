#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[31];
    int valor;
} Crianca;

Crianca criancas[100];

int main() {
    int N;
    
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;
        
        for (int i = 0; i < N; i++) {
            scanf("%s %d", criancas[i].nome, &criancas[i].valor);
        }
        
        int pos = 0;
        int count = criancas[0].valor;
        int restantes = N;
        
        while (restantes > 1) {
            int sentido = (count % 2 == 0) ? -1 : 1;
            
            int passos = count % restantes;
            if (passos == 0) passos = restantes;
            
            for (int i = 0; i < passos; i++) {
                if (sentido == 1) {
                    pos = (pos + 1) % N;
                } else {
                    pos = (pos - 1 + N) % N;
                }
                
                while (criancas[pos].valor == 0) {
                    if (sentido == 1) {
                        pos = (pos + 1) % N;
                    } else {
                        pos = (pos - 1 + N) % N;
                    }
                }
            }
            
            count = criancas[pos].valor;
            criancas[pos].valor = 0;
            restantes--;
        }
        
        for (int i = 0; i < N; i++) {
            if (criancas[i].valor != 0) {
                printf("Vencedor(a): %s\n", criancas[i].nome);
                break;
            }
        }
    }
    
    return 0;
}
