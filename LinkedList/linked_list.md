### What is Linked List

- Linked List is a linear data structure, in which elements are not stored at a contiguous location, rather they are linked using pointers. Linked List forms a series of connected nodes, where each node stores the data and the address of the next node.

- ***Node Structure***: A node in a linked list typically consists of two components:

    - ***Data***: It holds the actual value or data associated with the node.
    - ***Next Pointer or Reference***: It stores the memory address (reference) of the next node in - the sequence.

- ***Head and Tail***: The linked list is accessed through the head node, which points to the first node in the list. The last node in the list points to NULL or nullptr, indicating the end of the list. This node is known as the tail node.


### Why linked list data structure needed?
The main cases where we prefer linked list over arrays is due to ease of insertion and deletion in linked list

### Types of linked lists: 
There are mainly three types of linked lists:

- ***Single-linked list***: In a singly linked list, each node contains a reference to the next node in the sequence. Traversing a singly linked list is done in a forward direction.

- ***Double linked list***: In a doubly linked list, each node contains references to both the next and previous nodes. This allows for traversal in both forward and backward directions, but it requires additional memory for the backward reference.

- ***Circular linked list***: In a circular linked list, the last node points back to the head node, creating a circular structure. It can be either singly or doubly linked.

### Operations on Linked Lists

- ***Insertion***: Adding a new node to a linked list involves adjusting the pointers of the existing nodes to maintain the proper sequence. Insertion can be performed at the beginning, end, or any position within the list

- ***Deletion***: Removing a node from a linked list requires adjusting the pointers of the neighboring nodes to bridge the gap left by the deleted node. Deletion can be performed at the beginning, end, or any position within the list.

- ***Searching***: Searching for a specific value in a linked list involves traversing the list from the head node until the value is found or the end of the list is reached.