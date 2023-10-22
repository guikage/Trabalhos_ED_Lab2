#ifndef _salao_
#define _salao_

#include <stdbool.h>

typedef struct mesa Mesa;
typedef struct salao Salao;

struct mesa {
    int numero;
    int ocupantes;
    int comanda;
    bool arrumada;
    bool vaga;
};

struct salao {
    int linhas;
    int colunas;
    Mesa *mesas;
};

Salao *criar_salao(int linhas, int colunas);
Mesa *encontrar_mesa_disponivel(Salao *salao);
Mesa *encontrar_mesa_por_numero(Salao *salao, int numero);
void imprimir_salao(Salao *salao);
void imprimir_mesa(Mesa *mesa);

#endif
