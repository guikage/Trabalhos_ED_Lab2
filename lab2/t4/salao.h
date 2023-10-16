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
    bool disponivel;
};

struct salao {
    int linhas;
    int colunas;
    Mesa *mesa;
};

Salao *criar_salao(int linhas, int colunas);
Mesa *encontrar_mesa_disponivel(Salao *salao);

#endif
