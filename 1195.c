#include <stdlib.h>
#include <stdio.h>

typedef struct cel {
    int dado;
    struct cel *esq;
    struct cel *dir;
} celula;

typedef celula* arvore;

celula* cria_celula(int valor) {
    celula* nova_celula = (celula*)malloc(sizeof(celula));
    if (nova_celula == NULL) {
        fprintf(stderr, "Erro ao alocar memoria\n");
        return NULL;
    }
    nova_celula->dado = valor;
    nova_celula->esq = NULL;
    nova_celula->dir = NULL;
    return nova_celula;
}

arvore insere(arvore r, int valor){
    if(r == NULL){
        return cria_celula(valor);
    }
    if(valor < r->dado){
        r->esq = insere(r->esq, valor);
    } else {
        r->dir = insere(r->dir, valor);
    }
    return r;       
}

void pre_ordem(arvore r, int* primeiro){
    if(r != NULL){
        if(*primeiro) {
            printf("%d", r->dado);
            *primeiro = 0;
        } else {
            printf(" %d", r->dado);
        }
        pre_ordem(r->esq, primeiro);
        pre_ordem(r->dir, primeiro);
    }
}

void em_ordem(arvore r, int* primeiro){
    if(r != NULL){
        em_ordem(r->esq, primeiro);
        if(*primeiro) {
            printf("%d", r->dado);
            *primeiro = 0;
        } else {
            printf(" %d", r->dado);
        }
        em_ordem(r->dir, primeiro);
    }
}

void pos_ordem(arvore r, int* primeiro){
    if(r != NULL){
        pos_ordem(r->esq, primeiro);
        pos_ordem(r->dir, primeiro);
        if(*primeiro) {
            printf("%d", r->dado);
            *primeiro = 0;
        } else {
            printf(" %d", r->dado);
        }
    }
}

void libera_arvore(arvore r){
    if(r != NULL){
        libera_arvore(r->esq);
        libera_arvore(r->dir);
        free(r);
    }
}

int main(){   
    int c, n, o;
    scanf("%d", &c);
    
    for(int i = 0; i < c; i++){
        arvore r = NULL;
        scanf("%d", &n);
        
        for(int j = 0; j < n; j++){
            scanf("%d", &o); 
            r = insere(r, o);
        }
        
        printf("Case %d:\n", i + 1);
        
        int primeiro = 1;
        printf("Pre.: ");
        pre_ordem(r, &primeiro);
        printf("\n");
        
        primeiro = 1;
        printf("In..: ");
        em_ordem(r, &primeiro);
        printf("\n");
        
        primeiro = 1;
        printf("Post: ");
        pos_ordem(r, &primeiro);
        printf("\n");
        
        libera_arvore(r);

        if (i < c) {
            printf("\n");
        }
    }
    
    return 0;
}