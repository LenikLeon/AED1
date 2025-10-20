#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int X[N];
    int *ptr = X;
    for (int i = 0; i < N; i++) {
        scanf("%d", ptr + i);
    }
    int *menor = ptr; /
    int posicao = 0;
    for (int i = 1; i < N; i++) {
        if (*(ptr + i) < *menor) {
            menor = ptr + i;
            posicao = i;
        }
    }
    printf("Menor valor: %d\n", *menor);
    printf("Posicao: %d\n", posicao);
    return 0;
}
