#ifndef _MINHEAP_
#define _MINHEAP_

#define CAP_MAX 63

typedef struct minheap{
    int *arr; //o array usado para armazenar os dados
    int capacity; //capacidade atual do heap
    int size; //tamanho atual do heap/primeiro indice vazio
}MinHeap;

MinHeap *criaMinHeap(void);
void swap(int *a, int *b);
int getLeft(int i);
int getRight(int i);
int getParent(int i);
void insert(MinHeap *h, int v);
int pull(MinHeap *h);
int peek(MinHeap *h);
void imprimeHeap(MinHeap *h, int i);

#endif
