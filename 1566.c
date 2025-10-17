#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int nc;
    scanf("%d", &nc);
    while (nc--) {
        int n;
        scanf("%d", &n);
        int *alturas = (int *) malloc(n * sizeof(int));
        if (!alturas) return 1;
        for (int i = 0; i < n; i++)
            scanf("%d", &alturas[i]);
        qsort(alturas, n, sizeof(int), compara);
        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%d", alturas[i]);
        }
        printf("\n");
        free(alturas);
    }
    return 0;
}

