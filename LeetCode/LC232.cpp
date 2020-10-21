class MyQueue {
public:
    stack<int> st1, st2;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(st1.size()){
            st2.push(st1.top());
            st1.pop();
        }
        int ret = st2.top();
        st2.pop();
        while(st2.size()){
            st1.push(st2.top());
            st2.pop();
        }
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        while(st1.size()){
            st2.push(st1.top());
            st1.pop();
        }
        int ret = st2.top();
        while(st2.size()){
            st1.push(st2.top());
            st2.pop();
        }
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty();
    }
};