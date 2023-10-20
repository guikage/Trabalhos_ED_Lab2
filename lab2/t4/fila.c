#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *cria_fila(void){
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

void desistir_da_fila(Fila *fila, int senha){
    //recebe a fila e a senha do grupo que desistiu de esperar
    Grupo *p = fila->ini;
    Grupo *ant = NULL;
    while(p != NULL && p->senha != senha){
        ant = p;
        p = p->prox;
    }
    if(p == NULL){
    } else if(ant == NULL){
        fila->ini = fila->ini->prox;
    } else {
        ant->prox = p->prox;
        if(ant->prox == NULL){
            fila->fim = ant;
        }
    } 
}

int retirar_pessoas_da_fila(Fila *fila, int pessoas){
    //recebe a fila
    //retorna o numero de pessoas chamadas
    
    int n = 0;
    if(fila->ini != NULL){
        if(fila->ini->pessoas <= pessoas){
            n = fila->ini->pessoas;
            fila->ini = fila->ini->prox;
        } else {
            n = pessoas;
            fila->ini->pessoas -= pessoas;
        }
    }
    return n;
}

bool fila_vazia(Fila *fila){
    if(fila->ini == NULL && fila->fim == NULL) return true;
    return false;
}
