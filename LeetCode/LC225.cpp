class MyStack {
public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = q.size();
        while(n-- > 1) {
            q.push(q.front());
            q.pop();
        }
        int ret = q.front();
        q.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        int n = q.size();
        while(n-- > 1) {
            q.push(q.front());
            q.pop();
        }
        int ret = q.front();
        q.pop();
        push(ret);
        return ret;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};