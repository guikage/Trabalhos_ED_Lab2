#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

bool minimum_compare(int a, int b) {
    return a >= b;
}

bool maximum_compare(int a, int b) {
    return a <= b;
}

void op_insert(Heap *heap) {
    int v;
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &v);
    push_heap(heap, v);
}

void op_pop(Heap *heap) {
    if (is_heap_empty(heap)) {
        printf("O heap está vazio.\n");
        return;
    }

    printf("O valor %d foi retirado.\n", pop_heap(heap));
}

void op_peek(Heap *heap) {
    if (is_heap_empty(heap)) {
        printf("O heap está vazio.\n");
        return;
    }

    printf("O valor %d está no topo do heap.\n", peek_heap(heap));
}

void op_print(Heap *heap){
    printf("Árvore:\n");
    print_heap_tree(heap);

    printf("\nVetor:\n");
    print_heap_array(heap);
}

Heap ask_heap_ordering() {
    char option;

    printf("Tipos de heaps:\n");
    printf("a) Max-heap: o primeiro elemento possui maior valor.\n");
    printf("b) Min-heap: o primeiro elemento possui menor valor.\n");

    printf("\nQual tipo de heap você deseja? ");
    scanf(" %c", &option);

    if (option == 'a') {
        return create_heap(maximum_compare);
    }

    return create_heap(minimum_compare);
}


int main(){
    Heap heap = ask_heap_ordering();

    printf("\n> Menu:\n");
    printf("  a. inserir\n");
    printf("  b. remover\n");
    printf("  c. consultar\n");
    printf("  d. imprimir árvore e vetor\n");
    printf("  0. sair\n");

    char option;

    do {
        printf("\n> O que você deseja fazer? ");
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                op_insert(&heap);
                break;
            case 'b':
                op_pop(&heap);
                break;
            case 'c':
                op_peek(&heap);
                break;
            case 'd':
                op_print(&heap);
                break;
            case '0':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (option != '0');

    return 0;
}
