#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

const int INITIAL_CAPACITY = 7;

#define MAX(a, b) (a) > (b) ? (a) : (b)

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int get_left_node(int i) { return 2 * i + 1; }
int get_right_node(int i) { return 2 * i + 2; }
int get_parent_node(int i) { return (i - 1) / 2; }

bool exists_node(Heap *heap, int i) { return i < heap->size; }

void ensure_capacity(Heap *heap, int new_size) {
    if (new_size <= heap->capacity) {
        return;
    }

    int new_capacity = (heap->size + 1) * 2 - 1;

    heap->array = realloc(heap->array, sizeof(int) * new_capacity);
    heap->capacity = new_capacity;
}

Heap create_heap(bool (*compare)(int, int)) {
    Heap heap;
    heap.array = (int*)malloc(sizeof(int) * INITIAL_CAPACITY);
    heap.capacity = INITIAL_CAPACITY;
    heap.size = 0;
    heap.compare = compare;

    return heap;
}

bool is_heap_empty(Heap *heap) {
    return heap->size == 0;
}

void push_heap(Heap *heap, int value) {
    ensure_capacity(heap, heap->size + 1);

    heap->size++;
    
    int i = heap->size - 1;
    int parent = get_parent_node(i);

    heap->array[i] = value;

    while (i != 0 && heap->compare(heap->array[parent], heap->array[i])) {
        swap(&heap->array[i], &heap->array[parent]);
        i = parent;
        parent = get_parent_node(i);
    }
}

int pop_heap(Heap *heap) {
    int value = heap->array[0];
    heap->size--;

    swap(&heap->array[0], &heap->array[heap->size]);
    
    int i = 0;
    
    while (true) {
        int minimum = i;

        int left = get_left_node(i);
        int right = get_right_node(i);
    
        if (exists_node(heap, left) && heap->compare(heap->array[minimum], heap->array[left])) {
            minimum = left;
        } 

        if (exists_node(heap, right) && heap->compare(heap->array[minimum], heap->array[right])) {
            minimum = right;
        }

        if (i == minimum) {
            break;
        }

        swap(&heap->array[i], &heap->array[minimum]);
    }

    return value;
}

int peek_heap(Heap *heap) {
    return heap->array[0];
}

int log2i(int n) {
    int result = 0;

    while (n > 0) {
        result++;
        n >>= 1;
    }

    return result;
}

int pow2i(int expoent) {
    return 1 << expoent;
}

void print_repeated(const char *text, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s", text);
    }
}

void print_heap_tree(Heap *heap) {
    int maximum_depth = log2i(heap->size + 1);

    int layer_index = 0;
    int layer_nodes = 1;

    for (int depth = 1; depth <= maximum_depth; depth++) {
        int floor = maximum_depth - depth;
        
        int space_between = pow2i(floor + 2) - 1;
        int space_initial = pow2i(floor + 1);

        int lines = pow2i(floor) - 1;

        print_repeated(" ", space_initial - 1);
        
        for (int i = layer_index; i < layer_nodes + layer_index; i++) {
            if (!exists_node(heap, i)) {
                break;
            }

            printf("%03d", heap->array[i]);
            print_repeated(" ", space_between - 2);
        }

        printf("\n");

        for (int line = 1; line <= lines; line++) {
            int space_between_edges = 2 * line - 1;
            int space_between_subtree = space_between - 2 * line;

            print_repeated(" ", space_initial - line);

            for (int i = layer_index; i < layer_nodes + layer_index; i++) {
                int left = get_left_node(i);
                int right = get_right_node(i);

                printf(exists_node(heap, left) ? "/" : " ");
                print_repeated(" ", space_between_edges);
                
                printf(exists_node(heap, right) ? "\\" : " ");
                print_repeated(" ", space_between_subtree);
            }

            printf("\n");
        }

        layer_index += layer_nodes;
        layer_nodes *= 2;
    }
}

void print_heap_array(Heap *heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%03d ", heap->array[i]);
    }

    for (int i = heap->size; i < heap->capacity; i++) {
        printf("*** ");
    }
}
 
