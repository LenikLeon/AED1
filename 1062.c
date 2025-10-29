#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        if (N == 0) break;

        while (1) {
            int primeiro;
            if (scanf("%d", &primeiro) != 1) return 0;
            if (primeiro == 0) {
                printf("\n");
                break;
            }

            int *saida_desejada = (int*) malloc(sizeof(int) * N);
            saida_desejada[0] = primeiro;

            for (int i = 1; i < N; i++) {
                scanf("%d", &saida_desejada[i]);
            }

            int *pilha = (int*) malloc(sizeof(int) * (N + 1));
            int topo = 0;
            int proximo = 1;
            int possivel = 1;

            for (int i = 0; i < N; i++) {
                int desejado = saida_desejada[i];
                while ((topo == 0 || pilha[topo - 1] != desejado) && proximo <= N) {
                    pilha[topo++] = proximo++;
                }
                if (topo > 0 && pilha[topo - 1] == desejado) {
                    topo--;
                } else {
                    possivel = 0;
                    break;
                }
            }

            if (possivel)
                printf("Yes\n");
            else
                printf("No\n");

            free(saida_desejada);
            free(pilha);
        }
    }
    return 0;
}
