#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *criar_fila(void){
    //retorna o ponteiro para a struct fila criada
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->ini = NULL;
    fila->fim = NULL;
    return fila;
}

int entrar_na_fila(Fila *fila, int pessoas){
    //recebe a fila e o numero de pessoas que vao entrar na fila
    Grupo *n = (Grupo*)malloc(sizeof(Grupo));
    n->pessoas = pessoas;
    n->prox = NULL;
    if(fila->fim == NULL){
        n->senha = 1;
        fila->ini = n;
        fila->fim = n;
    } else {
        n->senha = fila->fim->senha+1;
        fila->fim->prox = n;
        fila->fim = n;
    }

    return n->senha;
}

int retirar_pessoas_da_fila(Fila *fila, int pessoas){
    //recebe a fila
    //retorna o numero de pessoas chamadas
    
    int n = 0;
    if(fila->ini != NULL){
        if(fila->ini->pessoas <= pessoas){
            n = fila->ini->pessoas;
            sair_da_fila(fila, fila->ini->senha);
        } else {
            n = pessoas;
            fila->ini->pessoas -= pessoas;
        }
    }
    return n;
}

bool sair_da_fila(Fila *fila, int senha){
    //recebe a fila e a senha do grupo que desistiu de esperar
    Grupo *p = fila->ini;
    Grupo *ant = NULL;
    while(p != NULL && p->senha != senha){
        ant = p;
        p = p->prox;
    }
    if(p == NULL){
        return 0;
    }

    if(ant == NULL){
        fila->ini = fila->ini->prox;
        if (fila->ini == NULL) {
            fila->fim = NULL;
        }
    } else {
        ant->prox = p->prox;
        if(ant->prox == NULL){
            fila->fim = ant;
        }
    }

    free(p);
    return 1;
}

bool esta_na_fila(Fila *fila, int senha) {
    for (Grupo *grupo = fila->ini; grupo != NULL; grupo = grupo->prox) {
        if (grupo->senha == senha) {
            return grupo;
        }
    }
    return NULL;
}


bool fila_vazia(Fila *fila){
    if(fila->ini == NULL && fila->fim == NULL) return true;
    return false;
}

void imprimir_fila(Fila *fila) {
    if (fila_vazia(fila)) {
        printf("• A fila de espera está vazia.\n");
        return;
    }

    for (Grupo *grupo = fila->ini; grupo != NULL; grupo = grupo->prox) {
        printf("• Grupo %2d: %3d pessoa(s)\n", grupo->senha, grupo->pessoas);
    }
}
