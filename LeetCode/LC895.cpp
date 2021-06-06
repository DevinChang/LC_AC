class FreqStack {
public:
    unordered_map<int,stack<int>> stk;
    unordered_map<int,int> cnt;
    int n = 0;

    FreqStack() {

    }
    
    void push(int val) {
        stk[++cnt[val]].push(val);
        n = max(n, cnt[val]);
    }
    
    int pop() {
        int t = stk[n].top();
        stk[n].pop();
        cnt[t]--;
        if(stk[n].empty()) n--;
        return t;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */