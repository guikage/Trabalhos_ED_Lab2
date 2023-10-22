#ifndef _mesas_
#define _mesas_

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
    Mesa *mesa;
};

Salao *criar_salao(int linhas, int colunas);
Mesa *encontrar_mesa_disponivel(Salao *salao);
Mesa *encontrar_mesa_por_numero(Salao *salao, int numero);

#endif
