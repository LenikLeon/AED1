#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50
#define MIN_ATTENDANCE 75.0

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        int n;
        scanf("%d", &n);
        
        char names[MAX_STUDENTS][MAX_NAME_LEN + 1];
        char attendance[MAX_STUDENTS][MAX_NAME_LEN * 10]; // Para armazenar registros de frequência
        
        // Ler nomes
        for (int i = 0; i < n; i++) {
            scanf("%s", names[i]);
        }
        
        // Ler registros de frequência
        for (int i = 0; i < n; i++) {
            scanf("%s", attendance[i]);
        }
        
        // Verificar cada estudante
        int first = 1; // Para controlar espaços na saída
        
        for (int i = 0; i < n; i++) {
            int total = 0;
            int present = 0;
            
            // Calcular presença
            for (int j = 0; attendance[i][j] != '\0'; j++) {
                if (attendance[i][j] == 'P') {
                    present++;
                    total++;
                } else if (attendance[i][j] == 'A') {
                    total++;
                }
                // 'M' não conta para total nem presença
            }
            
            // Calcular porcentagem
            double percentage = 0.0;
            if (total > 0) {
                percentage = (double)present / total * 100.0;
            }
            
            // Se frequência menor que 75%, incluir na saída
            if (percentage < MIN_ATTENDANCE) {
                if (!first) {
                    printf(" ");
                }
                printf("%s", names[i]);
                first = 0;
            }
        }
        
        printf("\n");
    }
    
    return 0;
}