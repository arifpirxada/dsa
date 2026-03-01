class myStack {
    queue<int> q1;
    queue<int> q2;

  public:

    void push(int x) {
        // Inserts an element x at the top of the stack
        if (q1.empty() && q2.empty())
            q1.push(x);
        else if (q1.empty()) {
            q2.push(x);
        } else {
            q1.push(x);
        }
    }

    void pop() {
        // Removes an element from the top of the stack
        if (q1.empty()) {
            while(!q2.empty()) {
                if (q2.size() > 1) {
                    q1.push(q2.front());
                }
                q2.pop();
            }
        } else {
            while(!q1.empty()) {
                if (q1.size() > 1) {
                    q2.push(q1.front());
                }
                q1.pop();
            }
        }
    }

    int top() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if (q1.empty()) {
            if (q2.empty()) return -1;
            return q2.back();
        } else {
            return q1.back();
        }
    }

    int size() {
        // Returns the current size of the stack
        if (q1.empty()) {
            return q2.size();
        } else {
            return q1.size();
        }
    }
};
