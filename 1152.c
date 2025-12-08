#include <stdio.h>
#include <stdlib.h>

#define MAX 200010

typedef struct {
    int u, v, peso;
} Aresta;

Aresta arestas[MAX];
int pai[MAX], tam[MAX];

// Funções Union-Find
int find(int x) {
    if (pai[x] != x)
        pai[x] = find(pai[x]);
    return pai[x];
}

void unionSet(int a, int b) {
    int raizA = find(a);
    int raizB = find(b);
    
    if (raizA != raizB) {
        if (tam[raizA] < tam[raizB]) {
            pai[raizA] = raizB;
            tam[raizB] += tam[raizA];
        } else {
            pai[raizB] = raizA;
            tam[raizA] += tam[raizB];
        }
    }
}

// Comparador para qsort
int comparar(const void *a, const void *b) {
    Aresta *arestaA = (Aresta *)a;
    Aresta *arestaB = (Aresta *)b;
    return arestaA->peso - arestaB->peso;
}

int main() {
    int m, n;
    
    while (scanf("%d %d", &m, &n) && (m != 0 || n != 0)) {
        long long somaTotal = 0;
        
        // Ler arestas
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
            somaTotal += arestas[i].peso;
        }
        
        // Ordenar arestas por peso (crescente)
        qsort(arestas, n, sizeof(Aresta), comparar);
        
        // Inicializar Union-Find
        for (int i = 0; i < m; i++) {
            pai[i] = i;
            tam[i] = 1;
        }
        
        // Kruskal
        long long somaMST = 0;
        int arestasUsadas = 0;
        
        for (int i = 0; i < n && arestasUsadas < m - 1; i++) {
            int u = arestas[i].u;
            int v = arestas[i].v;
            int peso = arestas[i].peso;
            
            if (find(u) != find(v)) {
                unionSet(u, v);
                somaMST += peso;
                arestasUsadas++;
            }
        }
        
        // Economia = total - MST
        long long economia = somaTotal - somaMST;
        printf("%lld\n", economia);
    }
    
    return 0;
}