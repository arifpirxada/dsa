#include <iostream>
#include <list>

using namespace std;

class Queue {
    private:
        list<int> ls;
    public:
        // bool isFull() {
        //     // Check if we can get more space
        //     int* newInteger = new int; 
        //     if (!newInteger) return true;
        //     return false;
        // }
        bool isEmpty() {
            if (ls.empty()) return true;
            return false;
        }
        void enqueue(int val) {
            ls.push_back(val);
        }
        int deque() {
            if (isEmpty()) {
                cout << "Queue Underflow!" << endl;
                return -1;
            }
            int val = ls.front();
            ls.pop_front();
            return val;
        }
        int peek(){
            return ls.front();
        }
        int rear() {
            return ls.back();
        }

        void queTraverse() {
            if (isEmpty()) {
                cout << "Queue Underflow!" << endl;
                return;
            }
            for (list<int>::iterator it = ls.begin(); it != ls.end(); ++it) {
                cout << *it << " ";
            }
        }
};

int main() {
    Queue myque;

    myque.enqueue(1);
    myque.enqueue(2);
    myque.enqueue(3);
    myque.enqueue(4);
    myque.enqueue(5);

    cout << "Enqueued 1 2 3 4 5" << endl;

    cout << "Dequeued " << myque.deque() << " ";
    cout << myque.deque() << endl;

    cout << "Front " << myque.peek() << endl;
    cout << "Rear " << myque.rear() << endl;

    myque.enqueue(9);
    myque.enqueue(10);

    cout << "Que Traverse" << endl;

    myque.queTraverse();

    return 0;
}