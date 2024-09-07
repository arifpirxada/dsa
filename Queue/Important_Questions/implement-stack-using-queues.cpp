// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:
    queue<int> que;
    
    void push(int x) {
        que.push(x);
        for (int i{}; i < que.size() - 1; i++) {
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop() {
        int val = que.front();
        que.pop();
        return val;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};