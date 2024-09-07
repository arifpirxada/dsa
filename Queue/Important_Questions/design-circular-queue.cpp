#include <vector>
using namespace std;

// https://leetcode.com/problems/design-circular-queue/

class MyCircularDeque {
private:
    vector<int> arr;
    int front, back, size;

public:
    MyCircularDeque (int n): arr(n), front(-1), back(-1), size(n) {}
    
    bool insertFront(int value) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return false;
        }
        if (isEmpty()) {
            front = 0;
            back = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        arr[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return false;
        }
        if (isEmpty()) {
            front = 0;
            back = 0;
        } else if (back == size - 1) {
            back = 0;
        } else {
            back++;
        }
        arr[back] = value;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return false;
        }
        if (front == back) {
            front = -1;
            back = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return false;
        }
        if (front == back) {
            front = -1;
            back = -1;
        } else if (back == 0) {
            back = size - 1;
        } else {
            back--;
        }
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return arr[back];
    }
    
    bool isEmpty() {
        return (front == -1);
    }
    
    bool isFull() {
        return ((back == size - 1 && front == 0) || (back + 1 == front));
    }
};