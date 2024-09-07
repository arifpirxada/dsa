// Double Ended Queue - DEQueue: it is a type of queue which does not follow FIFO (first in first out).
// We can perforn insertion and deletion from both ends that is:
// Insertion from front + rear & Deletion from front + rear;

// Two types of DEQueue:
// 1. Restriction Input DEQueue - Insertion from front not allowed
// 1. Restriction Output DEQueue - Deletion from rear not allowed
#include <vector>
#include <iostream>
using namespace std;

class DEQueue {
private:
    vector<int> arr;
    int front, back, size;

public:
    DEQueue (int n): arr(n), front(-1), back(-1), size(n) {}

    bool isFull() {
        return ((back == size - 1 && front == 0) || (back + 1 == front));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void pushBack(int val) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
            back = 0;
        } else if (back == size - 1) {
            back = 0;
        } else {
            back++;
        }
        arr[back] = val;
    }

    void pushFront(int val) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
            back = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        arr[front] = val;
    }

    int popBack() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return -1;
        }
        int poppedValue = arr[back];
        if (front == back) {
            front = -1;
            back = -1;
        } else if (back == 0) {
            back = size - 1;
        } else {
            back--;
        }
        return poppedValue;
    }

    int popFront() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return -1;
        }
        int poppedValue = arr[front];
        if (front == back) {
            front = -1;
            back = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        return poppedValue;
    }
};

int main() {
    DEQueue dq(5);

    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushFront(5);
    dq.pushFront(3);

    cout << "Pop Front: " << dq.popFront() << endl;
    cout << "Pop Back: " << dq.popBack() << endl;

    dq.pushBack(30);
    cout << "Pop Front: " << dq.popFront() << endl;
    cout << "Pop Front: " << dq.popFront() << endl;
    cout << "Pop Front: " << dq.popFront() << endl;

    return 0;
}