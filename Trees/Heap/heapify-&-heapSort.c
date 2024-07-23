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
// heapify function =>
void heapify(Heap* heap, int i);
void buildHeap(Heap *heap);

// Sort the heap array in ascending order =>
void heapSort(Heap *heap);


int main() {
    Heap* myHeap = createHeap(100);
    
    // Insert into heap randomly numbers
    myHeap->last++;
    myHeap->arr[myHeap->last] = 23;

    myHeap->last++;
    myHeap->arr[myHeap->last] = 34;

    myHeap->last++;
    myHeap->arr[myHeap->last] = 87;

    myHeap->last++;
    myHeap->arr[myHeap->last] = 12;

    myHeap->last++;
    myHeap->arr[myHeap->last] = 98;

    myHeap->last++;
    myHeap->arr[myHeap->last] = 67;

    myHeap->last++;
    myHeap->arr[myHeap->last] = 2;

    printf("Heap before Heapify: ");
    printHeap(myHeap);
    printf("\n");

    printf("Heap after Heapify: ");
    buildHeap(myHeap);
    printHeap(myHeap);
    printf("\n");

    printf("Heap after Heap Sort: ");
    heapSort(myHeap);
    printHeap(myHeap);
    printf("\n");

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

// For Max heap =>
void heapify(Heap* heap, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= heap->last && heap->arr[left] > heap->arr[largest]) {
        largest = left;
    } 
    if (right <= heap->last && heap->arr[right] > heap->arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap->arr, i, largest);
        heapify(heap, largest);
    }
}

void buildHeap(Heap *heap) {
    for (int i = (heap->last) / 2; i > 0; i--) {
        heapify(heap, i);
    }
}

void heapSort(Heap *heap) {
    int originalLast = heap->last;
    
    while (heap->last > 1) {
        swap(heap->arr, 1, heap->last);
        heap->last--;

        // Heapify the reduced heap
        heapify(heap, 1);
    }
    // Restore the heap size
    heap->last = originalLast;
}