#include <stdio.h>
#include <stdlib.h>

// Max Heap implementation;
typedef struct Heap
{
    int size;
    int last;
    int *arr;
} Heap;

void swap(int *arr, int i, int j);
Heap* createHeap(int size);
void printHeap(Heap* heap);
void heapInsert(Heap* heap, int val);
void heapDelete(Heap* heap); // Deletes root node from heap

int main() {
    Heap* myHeap = createHeap(100);
    heapInsert(myHeap, 50);
    heapInsert(myHeap, 53);
    heapInsert(myHeap, 29);
    heapInsert(myHeap, 43);
    heapInsert(myHeap, 39);
    heapInsert(myHeap, 83);

    printf("Heap before deletion: ");
    printHeap(myHeap);
    printf("\n");

    printf("Heap after deletion: ");
    heapDelete(myHeap);
    printHeap(myHeap);
    printf("\n");

    printf("Heap after second deletion: ");
    heapDelete(myHeap);
    printHeap(myHeap);

    free(myHeap->arr);
    free(myHeap);
    return 0;
}

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

Heap* createHeap(int size) {
    Heap* newHeap = (Heap*)malloc(sizeof(Heap));
    newHeap->size = size;
    newHeap->arr = (int*)malloc((size + 1) * sizeof(int));  // +1 for 1-based index
    newHeap->last = 0;

    return newHeap;
}

void printHeap(Heap* heap) {
    for (int i = 1; i <= heap->last; i++) {
        printf("%d ", heap->arr[i]);
    }
}

void heapInsert(Heap* heap, int val) {
    if (heap->last >= heap->size) {
        printf("Heap is full\n");
        return;
    }

    heap->last++;
    int index = heap->last;
    heap->arr[index] = val;

    // For max heap =>
    while (index > 1) {
        int parent = index / 2;
        if (heap->arr[parent] < heap->arr[index]) {
            // Swap
            swap(heap->arr, parent, index);
            index = parent;
        } else {
            break;
        }
    }
}

void heapDelete(Heap* heap) {
    if (heap->last == 0) {
        printf("Heap is already empty!");
    }

    // Set root nodes value = last node
    heap->arr[1] = heap->arr[heap->last];
    heap->last--; // Delete last node

    // Set root node to its correct position =>
    int i = 1;
    while (i <= heap->last) {
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;

        // Know the largest amoung children and swap with it =>
        if (heap->arr[leftChild] > heap->arr[rightChild]) {
            if (leftChild <= heap->last && heap->arr[i] < heap->arr[leftChild]) {
                swap(heap->arr, i, leftChild);
                i = leftChild;  
            } else {
                break;
            }
        } else {
            if (rightChild <= heap->last && heap->arr[i] < heap->arr[rightChild]) {
                swap(heap->arr, i, rightChild);
                i = rightChild;
            } else {
                break;
            }
        }

    }
}

/* 

HEAP BEFORE DELETION =>

83 50 53 43 39 29

              83
            /    \
           /      \
         50        53
        /  \      / 
      43    39   29


HEAP AFTER DELETION OF ROOT NODE =>

53 50 29 43 39

              53
            /    \
           /      \
         50        29
        /  \      
      43    39   

*/