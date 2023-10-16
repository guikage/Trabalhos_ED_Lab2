#include "restaurante.h"

Restaurante *criar_restaurante(int linhas, int colunas) {
    Restaurante *restaurante = (Restaurante *)malloc(sizeof(Restaurante));
    restaurante->salao = criar_salao(linhas, colunas);
    restaurante->pratos = criar_pilha_de_pratos();
    restaurante->fila = criar_fila();
    restaurante->prox_comanda = 1;

    return restaurante;
}

void chegar_ao_restaurante(Restaurante *restaurante, int pessoas) {
    int restante = pessoas;

    while (restante > 0) {
        Mesa *mesa = encontrar_mesa_disponivel(restaurante->salao);

        if (mesa == NULL) {
            break;
        }

        int ocupantes = restante % (LUGARES_POR_MESA + 1);

        ocupar_mesa(restaurante, mesa, ocupantes);
        printf("- %d pessoas para a mesa %d com a comanda %d\n", ocupantes, mesa->numero, mesa->comanda);
    }

    if (restante > 0) {
        int senha = entrar_na_fila(restaurante->fila, restante);

        printf("\n");
        printf("- Infelizmente, %d pessoas devem entrar na fila de espera\n");
        printf("- A senha na fila de espera é %d\n", senha);
    }
}

void liberar_mesa(Restaurante *restaurante, Mesa *mesa) {
    mesa->disponivel = true;
    arrumar_mesa(restaurante, mesa);
}

void arrumar_mesa(Restaurante *restaurante, Mesa *mesa) {
    if (contar_pratos(restaurante->pratos) < LUGARES_POR_MESA) {
        printf("Não existem pratos limpos suficientes para arrumar a mesa.\n");
        return;
    }

    mesa->ocupantes = 0;
    mesa->arrumada = true;

    desempilhar_pratos(restaurante->pratos, LUGARES_POR_MESA);
    chamar_da_fila_de_espera(restaurante, mesa);
}

void chamar_da_fila_de_espera(Restaurante *restaurante, Mesa *mesa) {
    int pessoas = retirar_pessoas_da_fila(restaurante->fila, LUGARES_POR_MESA);

    if (pessoas > 0) {
        printf("- Chamando %d pessoas do primeiro grupo para ocupar a mesa %d.\n", pessoas, mesa->numero);
        printf("- A comanda para a mesa é %d\n", mesa->comanda);
        ocupar_mesa(restaurante, mesa, pessoas);
    }
}

void ocupar_mesa(Restaurante *restaurante, Mesa *mesa, int pessoas) {
    mesa->ocupantes = pessoas;
    mesa->comanda = restaurante->prox_comanda++;
    mesa->arrumada = false;
    mesa->disponivel = false;

    restaurante->pratos = empilhar_pratos(restaurante->pratos, LUGARES_POR_MESA - pessoas);
}