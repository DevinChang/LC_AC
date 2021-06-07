class StockSpanner {
public:
    int k = 0;
    stack<int> day, price;

    StockSpanner() {
        day.push(-1);
        price.push(1e6);
    }
    
    int next(int x) {
        while(price.top() <= x) {
            day.pop();
            price.pop();
        }
        int res = k - day.top();
        day.push(k++);
        price.push(x);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */