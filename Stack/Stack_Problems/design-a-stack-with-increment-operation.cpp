// https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack {
private:
    int top, size, *arr;

public:
    CustomStack(int maxSize) {
        top = -1;
        size = maxSize;
        arr = new int[size];
    }
    
    void push(int x) {
        if (top >= size - 1) return;
        top++;
        arr[top] = x;
    }
    
    int pop() {
        if (top < 0) return -1;
        top--;
        return arr[top + 1];
    }
    
    void increment(int k, int val) {
        if (k > top) {
            for (int i = 0; i < top + 1; i++) {
                arr[i] += val;
            }
        } else {
            for (int i = 0; i < k; i++) {
                arr[i] += val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */