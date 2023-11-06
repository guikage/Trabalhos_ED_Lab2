#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void op_1(Heap *h){
    int v;
    printf("\nDigite o valor a ser inserido: ");
    scanf("%d", &v);
    push_heap(h, v);
}

void op_2(Heap *h){
    int v = pop_heap(h);
    printf("\nValor %d removido\n", v);
}

void op_3(Heap *h){
    print_heap(h);
}

int menu(Heap *h){
    int sel;
    printf("1: inserir\n2: remover\n3: imprimir\n0: sair\nDigite sua opcao: ");
    scanf("%d", &sel);
    switch(sel){
        case 0:
            return 0;
        case 1:
            op_1(h);
            return 1;
        case 2:
            op_2(h);
            return 1;
        case 3:
            op_3(h);
            return 1;
        default:
            return 1;
    }
}

bool minimum_compare(int a, int b) {
    return a >= b;
}

bool maximum_compare(int a, int b) {
    return a <= b;
}

int main(){
    Heap heap = create_heap(maximum_compare);
    print_heap(&heap);

    do{ }while(menu(&heap));
    return 0;
}
