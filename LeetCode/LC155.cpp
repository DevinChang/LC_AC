#include <iostream>
#include <stack>
using namespace std;



class MinStack { 
    stack<int> mins;
    stack<int> s;
public:
    /** initialize your data structure here. */
    MinStack(){
        
    }
    
    void push(int x) {
        s.push(x);
        if(mins.empty() || x <= mins.top())
            mins.push(x);
    }
    
    void pop() {
        if(s.top() == mins.top())
            mins.pop();
        if(!s.empty())
            s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};