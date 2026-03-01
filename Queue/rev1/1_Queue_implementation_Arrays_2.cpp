#include <iostream>

using namespace std;

class Queue {
    private:
        int capacity;
        int front;
        int rear;
        int* arr;
    
    public:

        Queue(int c) {
            capacity = c;
            front = -1;
            rear = -1;
            arr = new int[capacity];
        }

        ~Queue() {
            delete[] arr;
        }

        bool isFull() {
            return rear == capacity - 1;
        }

        bool isEmpty() {
            return front == rear;
        }

        void enqueue(int val) {
            if (isFull()) return;
            arr[++rear] = val;
        }

        int deque() {
            if (isEmpty()) return -1;

            int value = arr[++front];

            // 🔥 Reset queue if empty
            if (front == rear) {
                front = -1;
                rear = -1;
            }

            return value;
        }

        int getFront() {
            if (isEmpty()) return -1;
            return arr[front + 1];
        }
        
        int getRear() {
            if (isEmpty()) return -1;
            return arr[rear];
        }
};

int main() {
    Queue myque(10);

    myque.enqueue(1);
    myque.enqueue(2);
    myque.enqueue(3);
    myque.enqueue(4);
    myque.enqueue(5);

    cout << myque.deque() << endl;
    cout << myque.deque() << endl;
    cout << myque.deque() << endl;
    cout << myque.deque() << endl;
    cout << myque.deque() << endl;

    return 0;
}