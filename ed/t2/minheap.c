#include <stdio.h>
#include <stdlib.h>
#include "minheap.h"

MinHeap *criaMinHeap(void){
    MinHeap *h = (MinHeap*)malloc(sizeof(MinHeap));
    h->arr = (int*)malloc(sizeof(int) * CAP_MAX); //aloca um vetor de tamanho CAP_MAX
    h->capacity = CAP_MAX; //define capacidade atual como CAP_MAX
    h->size = 0;
    return h;
}

void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int getLeft(int i){ return 2*i + 1; }
int getRight(int i){ return 2*i + 2; }
int getParent(int i){ return (i-1)/2; }

void insert(MinHeap *h, int v){
    if(h->size >= h->capacity){
        printf("Capacidade maxima atingida.\n");
        return;
    }
    h->size++;
    int i = h->size - 1;
    h->arr[i] = v;
    int p = getParent(i);
    while(i > -1 && h->arr[p] > h->arr[i]){
        swap(&h->arr[i], &h->arr[p]);
        i = p;
        p = getParent(i);
    }
}

int pull(MinHeap *h){
    int v = h->arr[0];
    h->size--;
    swap(&h->arr[0], &h->arr[h->size]);
    int i = 0;
    int l = getLeft(i);
    int r = getRight(i);
    int menor = i;
    while(i < h->size){
        l = getLeft(i);
        r = getRight(i);
        if(l < h->size && h->arr[l] < h->arr[i]) menor = l;
        if(r < h->size && h->arr[r] < h->arr[menor]) menor = r;
        if(i == menor) break;
        swap(&h->arr[i], &h->arr[menor]);
        i = menor;
    }
    return v;
}

int peek(MinHeap *h){
    return h->arr[0];
}

void imprimeHeap(MinHeap *h, int i){
    if(i >= h->size) return;
    int l = getLeft(i);
    int r = getRight(i);
    printf("No %d: ", h->arr[i]);
    printf("Filho esq: ");
    if(l < h->size) printf("%d, ", h->arr[l]);
    else printf("vazio, ");
    printf("Filho dir: ");
    if(r < h->size) printf("%d", h->arr[r]);
    else printf("vazio");
    putchar('\n');
    imprimeHeap(h, l);
    imprimeHeap(h, r);
}
