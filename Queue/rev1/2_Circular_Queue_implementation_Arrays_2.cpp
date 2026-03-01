#include <iostream>

using namespace std;

class Queue {
    private:
        int size;
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
            size = 0;
        }

        ~Queue() {
            delete[] arr;
        }

        bool isFull() {
            return size == capacity;
        }

        bool isEmpty() {
            return size == 0;
        }

        void enqueue(int val) {
            if (isFull()) return;
            rear = (rear + 1) % capacity;
            arr[rear] = val;
            size++;
        }

        int deque() {
            if (isEmpty()) return -1;

            front = (front + 1) % capacity;
            size--;

            return arr[front];            
        }

        int getFront() {
            if (isEmpty()) return -1;
            return arr[(front + 1) % capacity];
        }
        
        int getRear() {
            if (isEmpty()) return -1;
            return arr[rear];
        }

        int getSize() {
            return size;
        }

        void queTraverse() {
            if (isEmpty()) return;
            int f = front;

            while (f != rear) {
                f = (f + 1) % capacity;
                cout << arr[f] << " ";
            }
        }
};

int main() {
    Queue myque(10);

    myque.enqueue(1);
    myque.enqueue(2);
    myque.enqueue(3);
    myque.enqueue(4);
    myque.enqueue(5);

    cout << "Enqueued 1 2 3 4 5" << endl;

    cout << "Dequeued " << myque.deque() << " ";
    cout << myque.deque() << endl;

    cout << "Size " << myque.getSize() << endl;
    cout << "Front " << myque.getFront() << endl;
    cout << "Rear " << myque.getRear() << endl;

    myque.enqueue(9);
    myque.enqueue(10);

    cout << "Que Traverse" << endl;

    myque.queTraverse();

    return 0;
}