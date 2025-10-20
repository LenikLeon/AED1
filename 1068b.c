#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000 // tamanho máximo de cada expressão

typedef struct No {
    char valor;
    struct No *prox;
} No;

void push(No **topo, char valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}

char pop(No **topo) {
    if (*topo == NULL)
        return '\0';
    No *temp = *topo;
    char valor = temp->valor;
    *topo = temp->prox;
    free(temp);
    return valor;
}

int pilhaVazia(No *topo) {
    return topo == NULL;
}

int main() {
    char expressao[MAX + 1];
    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        No *pilha = NULL;
        int correto = 1;
        for (int i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                push(&pilha, '(');
            } else if (expressao[i] == ')') {
                if (pilhaVazia(pilha)) {
                    correto = 0;
                    break;
                }
                pop(&pilha);
            }
        }
        if (!pilhaVazia(pilha)) {
            correto = 0;
        }
        while (!pilhaVazia(pilha)) {
            pop(&pilha);
        }
        if (correto)
            printf("correct\n");
        else
            printf("incorrect\n");
    }
    return 0;
}
