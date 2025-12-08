#include <stdio.h>
#include <string.h>
#include <ctype.h>

void primeira_passada(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            str[i] = str[i] + 3;
        }
    }
}

void segunda_passada(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void terceira_passada(char *str) {
    int len = strlen(str);
    int meio = len / 2;
    for (int i = meio; i < len; i++) {
        str[i] = str[i] - 1;
    }
}

int main() {
    int N;
    scanf("%d\n", &N); // Número de casos de teste

    for (int i = 0; i < N; i++) {
        char linha[1005];
        fgets(linha, 1005, stdin);
        
        // Remove newline se existir
        linha[strcspn(linha, "\n")] = '\0';
        
        primeira_passada(linha);
        segunda_passada(linha);
        terceira_passada(linha);
        
        printf("%s\n", linha);
    }

    return 0;
}