#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_LENGTH 201

int compare(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

int main() {
    char palavras[MAX_WORDS][MAX_LENGTH];
    int count = 0;
    char linha[201];
    
    while (fgets(linha, 200, stdin) != NULL) {
        int i = 0;
        while (linha[i] != '\0') {
            if (isalpha(linha[i])) {
                char palavra[201];
                int j = 0;
                while (isalpha(linha[i])) {
                    palavra[j++] = tolower(linha[i++]);
                }
                palavra[j] = '\0';
                
                int existe = 0;
                for (int k = 0; k < count; k++) {
                    if (strcmp(palavras[k], palavra) == 0) {
                        existe = 1;
                        break;
                    }
                }
                if (!existe && count < MAX_WORDS) {
                    strcpy(palavras[count++], palavra);
                }
            } else {
                i++;
            }
        }
    }
    
    qsort(palavras, count, sizeof(palavras[0]), compare);
    
    for (int i = 0; i < count; i++) {
        printf("%s\n", palavras[i]);
    }
    
    return 0;
}