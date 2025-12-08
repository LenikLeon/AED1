#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1010
#define INF INT_MAX

typedef struct {
    int v, peso;
    struct Node *next;
} Node;

Node *grafo[MAX];
int dist[MAX];
int visitado[MAX];

void addAresta(int u, int v, int p) {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->v = v;
    novo->peso = p;
    novo->next = grafo[u];
    grafo[u] = novo;
}

void dijkstra(int start, int N, int C, int custoRota[]) {
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }
    dist[start] = 0;
    
    for (int count = 0; count < N; count++) {
        // Encontrar vértice com menor distância
        int u = -1;
        int minDist = INF;
        for (int i = 0; i < N; i++) {
            if (!visitado[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        
        if (u == -1) break;
        visitado[u] = 1;
        
        // Se u é uma cidade da rota (0 <= u < C-1)
        if (u < C - 1) {
            // Só pode ir para u+1 (próximo na rota)
            for (Node *it = grafo[u]; it != NULL; it = it->next) {
                if (it->v == u + 1) {
                    int v = it->v;
                    int peso = it->peso;
                    if (dist[u] != INF && dist[u] + peso < dist[v]) {
                        dist[v] = dist[u] + peso;
                    }
                    break; // só há essa aresta permitida
                }
            }
        } else {
            // Para outras cidades, pode usar todas as arestas
            for (Node *it = grafo[u]; it != NULL; it = it->next) {
                int v = it->v;
                int peso = it->peso;
                
                // Se v < C-1 (cidade da rota, não última)
                // O caminho deve seguir a rota a partir de v
                // Mas no Dijkstra, apenas relaxamos a aresta normalmente
                // A restrição será aplicada quando v for processado
                if (dist[u] != INF && dist[u] + peso < dist[v]) {
                    dist[v] = dist[u] + peso;
                }
            }
        }
    }
}

int main() {
    int N, M, C, K;
    
    while (scanf("%d %d %d %d", &N, &M, &C, &K) && (N != 0 || M != 0 || C != 0 || K != 0)) {
        // Inicializar grafo
        for (int i = 0; i < N; i++) {
            grafo[i] = NULL;
        }
        
        // Ler estradas
        for (int i = 0; i < M; i++) {
            int U, V, P;
            scanf("%d %d %d", &U, &V, &P);
            addAresta(U, V, P);
            addAresta(V, U, P);
        }
        
        // Calcular custo acumulado da rota (de i até C-1)
        int custoRota[MAX] = {0};
        // Precisamos saber o custo de cada segmento da rota
        int custoAcumulado = 0;
        // Vamos primeiro calcular custo de i para i+1
        int custoSegmento[MAX] = {0};
        
        // Encontrar custos dos segmentos da rota
        for (int i = 0; i < C - 1; i++) {
            // Procurar aresta entre i e i+1
            for (Node *it = grafo[i]; it != NULL; it = it->next) {
                if (it->v == i + 1) {
                    custoSegmento[i] = it->peso;
                    break;
                }
            }
        }
        
        // Calcular custo acumulado de cada ponto da rota até o destino C-1
        for (int i = C - 2; i >= 0; i--) {
            custoAcumulado += custoSegmento[i];
            custoRota[i] = custoAcumulado;
        }
        custoRota[C - 1] = 0;
        
        // Executar Dijkstra
        dijkstra(K, N, C, custoRota);
        
        // A resposta é o mínimo entre:
        // 1. Ir direto para C-1 sem passar por rota (se possível)
        // 2. Para cada i (0 <= i < C): dist[K][i] + custoRota[i]
        int resposta = INF;
        
        // Caso 1: Chegar direto em C-1 (se C-1 >= C, ou seja, se destino está fora da rota? Não, destino é C-1)
        resposta = dist[C - 1];
        
        // Caso 2: Passar por algum ponto da rota
        for (int i = 0; i < C; i++) {
            if (dist[i] != INF) {
                int custoTotal = dist[i] + custoRota[i];
                if (custoTotal < resposta) {
                    resposta = custoTotal;
                }
            }
        }
        
        printf("%d\n", resposta);
        
        // Liberar memória
        for (int i = 0; i < N; i++) {
            Node *it = grafo[i];
            while (it != NULL) {
                Node *temp = it;
                it = it->next;
                free(temp);
            }
        }
    }
    
    return 0;
}