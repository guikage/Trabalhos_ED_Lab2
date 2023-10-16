typedef struct prato Prato;

struct prato {
    struct prato *prox;        
};

Prato *criar_pilha_de_pratos();

Prato *empilhar_pratos(Prato *pilha, int n);
Prato *desempilhar_pratos(Prato *pilha, int n);

Prato *empilhar_prato(Prato *pilha);
Prato *desempilhar_prato(Prato *pilha);

int contar_pratos(Prato *pilha); 