#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_APPS 100
#define APP_LEN 21
#define MAX_SERVERS 200
#define MAX_CLIENTS 200

int main() {
    int N, M;
    
    while (1) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;
        
        // Armazenar aplicações dos servidores
        char servidores[MAX_SERVERS][MAX_APPS][APP_LEN];
        int qtd_servidor[MAX_SERVERS] = {0};
        
        for (int i = 0; i < N; i++) {
            int Q;
            scanf("%d", &Q);
            qtd_servidor[i] = Q;
            for (int j = 0; j < Q; j++) {
                scanf("%s", servidores[i][j]);
            }
        }
        
        // Armazenar aplicações dos clientes
        char clientes[MAX_CLIENTS][MAX_APPS][APP_LEN];
        int qtd_cliente[MAX_CLIENTS] = {0};
        
        for (int i = 0; i < M; i++) {
            int P;
            scanf("%d", &P);
            qtd_cliente[i] = P;
            for (int j = 0; j < P; j++) {
                scanf("%s", clientes[i][j]);
            }
        }
        
        // Contar conexões
        int total_conexoes = 0;
        
        for (int c = 0; c < M; c++) { // para cada cliente
            for (int s = 0; s < N; s++) { // para cada servidor
                int conectado = 0;
                // Verificar se há alguma aplicação em comum
                for (int i = 0; i < qtd_cliente[c] && !conectado; i++) {
                    for (int j = 0; j < qtd_servidor[s] && !conectado; j++) {
                        if (strcmp(clientes[c][i], servidores[s][j]) == 0) {
                            conectado = 1;
                        }
                    }
                }
                if (conectado) {
                    total_conexoes++;
                }
            }
        }
        
        printf("%d\n", total_conexoes);
    }
    
    return 0;
}