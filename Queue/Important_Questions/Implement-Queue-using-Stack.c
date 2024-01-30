#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

// Initialize a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Push an element onto the stack
void push(Stack* stack, int x) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = x;
    }
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return -1;  // Stack is empty
}

// Get the top element of the stack without popping it
int peek(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    }
    return -1;  // Stack is empty
}

// Free the memory allocated for the stack
void freeStack(Stack* stack) {
    free(stack->data);
    free(stack);
}

// Define MyQueue structure using two stacks
typedef struct {
    Stack* stack1;  // For enqueue operation
    Stack* stack2;  // For dequeue operation
} MyQueue;

// Initialize MyQueue
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stack1 = createStack(1000);
    queue->stack2 = createStack(1000);
    return queue;
}

// Enqueue operation
void myQueuePush(MyQueue* obj, int x) {
    push(obj->stack1, x);
}

// Dequeue operation
int myQueuePop(MyQueue* obj) {
    if (isEmpty(obj->stack2)) {
        while (!isEmpty(obj->stack1)) {
            push(obj->stack2, pop(obj->stack1));
        }
    }
    return pop(obj->stack2);
}

// Peek operation
int myQueuePeek(MyQueue* obj) {
    if (isEmpty(obj->stack2)) {
        while (!isEmpty(obj->stack1)) {
            push(obj->stack2, pop(obj->stack1));
        }
    }
    return peek(obj->stack2);
}

// Check if the queue is empty
bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->stack1) && isEmpty(obj->stack2);
}

// Free the memory allocated for MyQueue
void myQueueFree(MyQueue* obj) {
    freeStack(obj->stack1);
    freeStack(obj->stack2);
    free(obj);
}