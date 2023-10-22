#include "restaurante.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#include <stdlib.h>

Restaurante *criar_restaurante(int linhas, int colunas) {
    Restaurante *restaurante = (Restaurante *)malloc(sizeof(Restaurante));
    restaurante->salao = criar_salao(linhas, colunas);
    restaurante->pratos = criar_pilha_de_pratos();
    restaurante->fila = criar_fila();
    restaurante->prox_comanda = 1;

    return restaurante;
}

void ocupar_mesa(Restaurante *restaurante, Mesa *mesa, int pessoas) {
    mesa->ocupantes = pessoas;
    mesa->comanda = restaurante->prox_comanda++;
    mesa->arrumada = false;
    mesa->vaga = false;

    restaurante->pratos = empilhar_pratos(restaurante->pratos, LUGARES_POR_MESA - pessoas);
}

void chegar_ao_restaurante(Restaurante *restaurante, int pessoas) {
    int restante = pessoas;

    while (restante > 0) {
        Mesa *mesa = encontrar_mesa_disponivel(restaurante->salao);

        if (mesa == NULL) {
            break;
        }

        int ocupantes = MIN(restante, LUGARES_POR_MESA);
        restante -= ocupantes;

        ocupar_mesa(restaurante, mesa, ocupantes);
        printf("• %d pessoa(s) pode(m) ocupar a mesa %d com a comanda %d.\n", ocupantes, mesa->numero, mesa->comanda);
    }

    if (restante > 0) {
        int senha = entrar_na_fila(restaurante->fila, restante);

        printf("\n");
        printf("• Infelizmente, %d pessoa(s) deve(m) esperar na fila.\n", restante);
        printf("• A senha na fila de espera é %d.\n", senha);
    }
}

bool liberar_mesa(Restaurante *restaurante, Mesa *mesa) {
    if (mesa->vaga) {
        printf("• A mesa não está ocupada para ser liberada.\n");
        return false;
    }

    mesa->vaga = true;

    return true;
}

bool arrumar_mesa(Restaurante *restaurante, Mesa *mesa) {
    if (mesa->arrumada) {
        printf("• A mesa já está arrumada.\n");\
        return false;
    }

    if (!mesa->vaga) {
        printf("• A mesa não podê ser arrumada, pois está ocupada no momento.\n");\
        return false;
    }

    if (contar_pratos(restaurante->pratos) < LUGARES_POR_MESA) {
        printf("• A mesa não podê ser arrumada, pois não existem pratos suficientes na pilha.\n");
        return false;
    }

    mesa->ocupantes = 0;
    mesa->arrumada = true;

    restaurante->pratos = desempilhar_pratos(restaurante->pratos, LUGARES_POR_MESA);

    return true;
}

bool chamar_da_fila_de_espera(Restaurante *restaurante, Mesa *mesa) {
    int pessoas = retirar_pessoas_da_fila(restaurante->fila, LUGARES_POR_MESA);

    if (pessoas <= 0) {
        printf("• A fila de espera está vazia.\n");
        return false;
    }

    printf("• %d pessoa(s) do primeiro grupo pode(m) ocupar a mesa %d com a comanda %d.\n", pessoas, mesa->numero, mesa->comanda);
    ocupar_mesa(restaurante, mesa, pessoas);

    return true;
}

