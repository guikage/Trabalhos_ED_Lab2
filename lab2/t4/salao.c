#include <stdio.h>
#include <stdlib.h>
#include "salao.h"

Salao *criar_salao(int linhas, int colunas){
    Salao *salao = (Salao*)malloc(sizeof(Salao));
    salao->linhas = linhas;
    salao->colunas = colunas;
    salao->mesas = (Mesa*)malloc(linhas * colunas * sizeof(Mesa));
    for(int i = 0; i < linhas * colunas; i++){
        salao->mesas[i].numero = i+1;
        salao->mesas[i].arrumada = true;
        salao->mesas[i].vaga = true;
        salao->mesas[i].ocupantes = 0;
        salao->mesas[i].comanda = 0;
    }
    return salao;
}

Mesa *encontrar_mesa_disponivel(Salao *salao){
    for(int i = 0; i < salao->linhas * salao->colunas; i++){
        if(salao->mesas[i].vaga && salao->mesas[i].arrumada) return &salao->mesas[i];
    }
    return NULL;
}

Mesa *encontrar_mesa_por_numero(Salao *salao, int numero){
    for(int i = 0; i < salao->linhas * salao->colunas; i++){
        if(salao->mesas[i].numero == numero) return &salao->mesas[i];
    }
    return NULL;
}

void imprimir_salao(Salao *salao) {
    for(int i = 0; i < salao->linhas * salao->colunas; i++){
        imprimir_mesa(&salao->mesas[i]);
        printf("\n");
    }
}

void imprimir_mesa(Mesa *mesa) {
    printf("• Mesa %d\n", mesa->numero);
    
    if (mesa->arrumada) {
        printf("  Estado:  Disponível\n");
        return;
    }

    if (mesa->vaga) {
        printf("  Estado:  Suja\n");
        printf("  Pratos:  %d\n", mesa->ocupantes);
        return;
    }

    printf("  Estado:  Ocupada\n");
    printf("  Comanda: %d\n", mesa->comanda);
    printf("  Pessoas: %d\n", mesa->ocupantes);
}
