#include <stdio.h>
#include <stdlib.h>
#include "salao.h"

Salao *criar_salao(int linhas, int colunas){
    Salao *salao = (Salao*)malloc(sizeof(Salao));
    salao->linhas = linhas;
    salao->colunas = colunas;
    salao->mesa = (Mesa*)malloc(linhas * colunas * sizeof(Mesa));
    for(int i = 0; i < linhas * colunas; i++){
        salao->mesa[i].numero = i+1;
        salao->mesa[i].disponivel = true;
        salao->mesa[i].ocupantes = 0;
        salao->mesa[i].comanda = 0;
    }
    return salao;
}

Mesa *encontrar_mesa_disponivel(Salao *salao){
    for(int i = 0; i < salao->linhas * salao->colunas; i++){
        if(salao->mesa[i].disponivel && salao->mesa[i].arrumada) return &(salao->mesa[i]);
    }
    return NULL;
}

Mesa *encontrar_mesa_por_numero(Salao *salao, int numero){
    for(int i = 0; i < salao->linhas * salao->colunas; i++){
        if(salao->mesa[i].numero == numero) return &(salao->mesa[i]);
    }
    return NULL;
}
