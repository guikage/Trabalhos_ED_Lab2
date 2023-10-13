#ifndef _fila_
#define _fila_

struct lista{
    int senha;
    int pessoas;
    struct lista *prox;
};
typedef struct lista Lista;

struct fila{
    Lista *ini;
    Lista *fim;
};
typedef struct fila Fila;

Fila *cria_fila(void);
void entrar_fila(Fila *fila, int pessoas);
void desistir_fila(Fila *fila, int senha);
int chamar_primeiro_fila(Fila *fila);

#endif
