#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int doc;
    struct Node* next;
} Node;

int dfs(int v, Node** grafo, int* visitado, int* pilha_recursao) {
    if (!visitado[v]) {
        visitado[v] = 1;
        pilha_recursao[v] = 1;
        
        Node* atual = grafo[v];
        while (atual != NULL) {
            int vizinho = atual->doc;
            if (!visitado[vizinho]) {
                if (dfs(vizinho, grafo, visitado, pilha_recursao))
                    return 1;
            } else if (pilha_recursao[vizinho]) {
                return 1;
            }
            atual = atual->next;
        }
    }
    pilha_recursao[v] = 0;
    return 0;
}

int tem_ciclo(int n, Node** grafo) {
    int* visitado = calloc(n + 1, sizeof(int));
    int* pilha_recursao = calloc(n + 1, sizeof(int));
    int resultado = 0;
    
    for (int i = 1; i <= n && !resultado; i++) {
        if (!visitado[i]) {
            if (dfs(i, grafo, visitado, pilha_recursao))
                resultado = 1;
        }
    }
    
    free(visitado);
    free(pilha_recursao);
    return resultado;
}

void adicionar_aresta(Node** grafo, int a, int b) {
    Node* novo = malloc(sizeof(Node));
    novo->doc = b;
    novo->next = grafo[a];
    grafo[a] = novo;
}

void liberar_grafo(Node** grafo, int n) {
    for (int i = 1; i <= n; i++) {
        Node* atual = grafo[i];
        while (atual != NULL) {
            Node* temp = atual;
            atual = atual->next;
            free(temp);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        
        // Alocar grafo como array de listas encadeadas
        Node** grafo = calloc(N + 1, sizeof(Node*));
        
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            adicionar_aresta(grafo, A, B);
        }
        
        if (tem_ciclo(N, grafo))
            printf("SIM\n");
        else
            printf("NAO\n");
        
        liberar_grafo(grafo, N);
        free(grafo);
    }
    
    return 0;
}