#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M);
    
    while (M--) {
        int L;
        scanf("%d", &L);
        
        int vagao[50];
        for (int i = 0; i < L; i++) {
            scanf("%d", &vagao[i]);
        }
        
        int trocas = 0;
        for (int i = 0; i < L - 1; i++) {
            for (int j = 0; j < L - i - 1; j++) {
                if (vagao[j] > vagao[j + 1]) {
                    int temp = vagao[j];
                    vagao[j] = vagao[j + 1];
                    vagao[j + 1] = temp;
                    trocas++;
                }
            }
        }
        
        printf("Optimal train swapping takes %d swaps.\n", trocas);
    }
    
    return 0;
}