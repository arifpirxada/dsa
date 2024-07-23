# Heap

## Heap is a Complete Binary Tree (CBT) that comes with a "heap order property".

### Heap Order Property

1. **Min-Heap Order Property**: In a min-heap, the value of each node is greater than or equal to the value of its parent node.

2. **Max-Heap Order Property**: In a max-heap, the value of each node is less than or equal to the value of its parent node.

### Points

- If a node is at index `i` (for a 1 indexed heap), then its:
  - Left child = `2 * i` index.
  - Right child = `2 * i + 1` index.
  - Parent = `i / 2`

- Indexes of Leaf nodes are from:
  - `(n/2) + 1` to `n`
  - Example: For a heap of size 5 (1 indexed):
    - Leaf nodes are: `(5/2) + 1` to `5`
    - That is: `3` to `5`

### Insertion in Heap

- Insert the element at the end of the heap.
- Then compare it with the parent, swap it with the parent until it is greater than its parent (in case of max heap).

### Deletion of Root Node in Heap

- Swap the root element with the last element.
- Delete the last element by reducing the size or `last--`.
- Now, swap the root element until it is lesser than its child (But the child should be greater among the two).

### Heap Implementation

#### Output of `implementation.c`:

**HEAP BEFORE DELETION**

`83 50 53 43 39 29`

              83
            /    \
           /      \
         50        53
        /  \      / 
      43    39   29


HEAP AFTER DELETION OF ROOT NODE =>

`53 50 29 43 39`

              53
            /    \
           /      \
         50        29
        /  \      
      43    39


### Heapify Algorithm:

- It is an algorithm which converts a tree into heap. It is given an index and it converts the tree into heap from that index.

**Heapify Implementation:**
- We know the indices of leaf nodes, as discussed in points above.
- Now, swap the root element until it is lesser than its child (But the child should be greater among the two).