#ifndef _mesas_
#define _mesas_

#include <stdbool.h>

struct mesa {
    int numero;
    bool disponivel;
    int pessoas;
    int comanda;
};
typedef struct mesa Mesa;

Mesa *distribui_mesas(int m, int n);
int preenche_mesa(Mesa *mesas, int m, int n, int pessoas);
int esvazia_mesa(Mesa *mesas, int numero);

#endif
