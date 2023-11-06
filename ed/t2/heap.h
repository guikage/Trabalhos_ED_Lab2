#ifndef _HEAP_
#define _HEAP_

#include <stdbool.h>

/*
- array
  Vetor utilizado para armzenador os dados.

- capacity
  Capacidade máxima do vetor.

- size
  Capacidade ocupada do vetor.
  (índice do próximo elemento a ser inserido)

- compare
  Uma expressão binária que deve retornar `true` se `a` é considerado
  anterior a `b`.
  O elemento a ser removido é sempre o último de acordo com esta ordem.
*/
typedef struct heap
{
    int *array;
    int capacity;
    int size;
    bool (*compare)(int, int);
} Heap;

Heap create_heap(bool (*compare)(int, int));

void push_heap(Heap *heap, int value);
int pop_heap(Heap *heap);

void print_heap(Heap *heap);

bool is_heap_empty(Heap *heap);

#endif
