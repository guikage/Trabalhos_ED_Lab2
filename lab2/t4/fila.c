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

int entrar_fila(Fila *fila, int pessoas){
    //recebe a fila e o numero de pessoas que vao entrar na fila
    Lista *n = (Lista*)malloc(sizeof(Lista));
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

void desistir_fila(Fila *fila, int senha){
    //recebe a fila e a senha do grupo que desistiu de esperar
    Lista *p = fila->ini;
    Lista *ant = NULL;
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

int retirar_pessoas_da_fila(Fila *fila){
    //recebe a fila
    //retorna o numero de pessoas chamadas
    
    int n = 0;
    if(fila->ini != NULL){
        if(fila->ini->pessoas <= 4){
            n = fila->ini->pessoas;
            fila->ini = fila->ini->prox;
        } else {
            n = 4;
            fila->ini->pessoas -= 4;
        }
    }
    return n;
}
