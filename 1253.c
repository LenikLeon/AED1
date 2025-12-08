#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char texto[51];
        int K;
        scanf("%s", texto);
        scanf("%d", &K);

        for (int j = 0; texto[j] != '\0'; j++) {
            if (texto[j] >= 'A' && texto[j] <= 'Z') {
                // Decodificar: mover K posições para esquerda
                char decoded = texto[j] - K;
                if (decoded < 'A') {
                    decoded += 26;
                }
                texto[j] = decoded;
            }
        }

        printf("%s\n", texto);
    }

    return 0;
}