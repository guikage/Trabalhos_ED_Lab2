#ifndef _fila_
#define _fila_

#include <stdbool.h>

typedef struct grupo Grupo;
typedef struct fila Fila;

struct grupo {
    int senha;
    int pessoas;
    struct grupo *prox;
};

struct fila {
    Grupo *ini;
    Grupo *fim;
};

Fila *criar_fila(void);
int entrar_na_fila(Fila *fila, int pessoas);
void desistir_da_fila(Fila *fila, int senha);
int retirar_pessoas_da_fila(Fila *fila, int pessoas);
bool fila_vazia(Fila *fila);

#endif
