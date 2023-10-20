#ifndef _restaurante_
#define _restaurante_

#include <stdio.h>

#include "salao.h"
#include "pratos.h"
#include "fila.h"

#define LUGARES_POR_MESA 4

typedef struct restaurante Restaurante;

struct restaurante {
    Salao *salao;
    Prato *pratos;

    Fila *fila;

    int prox_comanda;
};

Restaurante *criar_restaurante(int linhas, int colunas);
void chegar_ao_restaurante(Restaurante *restaurante, int pessoas);
void liberar_mesa(Restaurante *restaurante, Mesa *mesa);
void arrumar_mesa(Restaurante *restaurante, Mesa *mesa);
void chamar_da_fila_de_espera(Restaurante *restaurante, Mesa *mesa);


#endif
