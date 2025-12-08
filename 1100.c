#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 8

typedef struct {
    int x, y, dist;
} Posicao;

int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

int bfs(int startX, int startY, int endX, int endY) {
    if (startX == endX && startY == endY) return 0;
    
    int visited[SIZE][SIZE] = {0};
    Posicao fila[SIZE * SIZE];
    int frente = 0, tras = 0;
    
    fila[tras].x = startX;
    fila[tras].y = startY;
    fila[tras].dist = 0;
    tras++;
    visited[startX][startY] = 1;
    
    while (frente < tras) {
        Posicao atual = fila[frente];
        frente++;
        
        for (int i = 0; i < 8; i++) {
            int nx = atual.x + dx[i];
            int ny = atual.y + dy[i];
            
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && !visited[nx][ny]) {
                if (nx == endX && ny == endY) {
                    return atual.dist + 1;
                }
                visited[nx][ny] = 1;
                fila[tras].x = nx;
                fila[tras].y = ny;
                fila[tras].dist = atual.dist + 1;
                tras++;
            }
        }
    }
    return -1; // não deveria acontecer em tabuleiro conectado
}

int main() {
    char inicio[3], fim[3];
    
    while (scanf("%s %s", inicio, fim) != EOF) {
        // Converter coordenadas: 'a'..'h' -> 0..7, '1'..'8' -> 0..7
        int startX = inicio[0] - 'a';
        int startY = inicio[1] - '1';
        int endX = fim[0] - 'a';
        int endY = fim[1] - '1';
        
        int moves = bfs(startX, startY, endX, endY);
        
        printf("To get from %s to %s takes %d knight moves.\n", inicio, fim, moves);
    }
    
    return 0;
}