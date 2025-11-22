#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, k, m;
    
    while (1) {
        scanf("%d %d %d", &N, &k, &m);
        
        // Condição de parada
        if (N == 0 && k == 0 && m == 0) {
            break;
        }
        
        // Array para marcar pessoas ainda presentes (1 = presente, 0 = removida)
        int pessoas[21] = {0};
        for (int i = 1; i <= N; i++) {
            pessoas[i] = 1;
        }
        
        int presentes = N;
        int horario = 1;      // Começa na pessoa 1 (sentido horário)
        int anti_horario = N; // Começa na pessoa N (sentido anti-horário)
        
        // Enquanto ainda houver pessoas
        while (presentes > 0) {
            // Encontrar próxima pessoa no sentido horário
            int count = 0;
            while (count < k) {
                if (pessoas[horario]) {
                    count++;
                }
                if (count < k) {
                    horario++;
                    if (horario > N) horario = 1;
                }
            }
            
            // Encontrar próxima pessoa no sentido anti-horário
            count = 0;
            while (count < m) {
                if (pessoas[anti_horario]) {
                    count++;
                }
                if (count < m) {
                    anti_horario--;
                    if (anti_horario < 1) anti_horario = N;
                }
            }
            
            // Remover as pessoas selecionadas
            if (horario == anti_horario) {
                // Mesma pessoa selecionada pelos dois contadores
                printf("%3d", horario);
                pessoas[horario] = 0;
                presentes--;
            } else {
                // Pessoas diferentes selecionadas
                printf("%3d%3d", horario, anti_horario);
                pessoas[horario] = 0;
                pessoas[anti_horario] = 0;
                presentes -= 2;
            }
            
            // Imprimir vírgula se ainda há pessoas
            if (presentes > 0) {
                printf(",");
            }
            
            // Encontrar próxima pessoa válida para horário
            if (presentes > 0) {
                do {
                    horario++;
                    if (horario > N) horario = 1;
                } while (!pessoas[horario]);
                
                // Encontrar próxima pessoa válida para anti-horário
                do {
                    anti_horario--;
                    if (anti_horario < 1) anti_horario = N;
                } while (!pessoas[anti_horario]);
            }
        }
        printf("\n");
    }
    
    return 0;
}