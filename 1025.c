#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, Q;
    int case_num = 1;
    
    while (1) {
        scanf("%d %d", &N, &Q);
        if (N == 0 && Q == 0) break;
        
        int marbles[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &marbles[i]);
        }
        
        // Ordenar os mármores
        qsort(marbles, N, sizeof(int), compare);
        
        printf("CASE# %d:\n", case_num);
        
        for (int i = 0; i < Q; i++) {
            int query;
            scanf("%d", &query);
            
            // Busca binária
            int left = 0, right = N - 1;
            int found_index = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (marbles[mid] == query) {
                    found_index = mid;
                    right = mid - 1; // Continuar buscando à esquerda para achar a primeira ocorrência
                } else if (marbles[mid] < query) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            if (found_index != -1) {
                printf("%d found at %d\n", query, found_index + 1);
            } else {
                printf("%d not found\n", query);
            }
        }
        
        case_num++;
    }
    
    return 0;
}