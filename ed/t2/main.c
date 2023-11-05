#include <stdio.h>
#include <stdlib.h>
#include "minheap.h"

void op_1(MinHeap *h){
    int v;
    printf("\nDigite o valor a ser inserido: ");
    scanf("%d", &v);
    insert(h, v);
}

void op_2(MinHeap *h){
    int v = pull(h);
    printf("\nValor %d removido\n", v);
}

void op_3(MinHeap *h){
    imprimeHeap(h, 0);
}

int menu(MinHeap *h){
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

int main(){
    MinHeap *h = criaMinHeap();
    do{ }while(menu(h));
    return 0;
}
