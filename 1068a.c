#include <stdio.h>
#include <string.h>

#define MAX 1000   // tamanho máximo de cada expressão
#define N 10000    // quantidade máxima de expressões

int main() {
    char expressao[MAX + 1];
    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        int pilha[MAX];
        int topo = -1;
        int correto = 1;
        for (int i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                pilha[++topo] = '(';
            } 
            else if (expressao[i] == ')') {
                if (topo == -1) {
                    correto = 0;
                    break;
                }
                topo--;
            }
        }
        if (topo != -1) {
            correto = 0;
        }
        if (correto)
            printf("correct\n");
        else
            printf("incorrect\n");
    }
    return 0;
}
