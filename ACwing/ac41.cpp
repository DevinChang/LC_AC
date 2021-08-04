class MinStack {
	stack<int> stk, min_stk;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
		stk.push(x);
		if(min_stk.empty() || min_stk.top() >= x) min_stk.push(x);
    }
    
    void pop() {
		if(stk.top() == min_stk.top()) min_stk.pop();
		stk.pop();
    }
    
    int top() {
		return stk.top();
    }
    
    int getMin() {
		return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */