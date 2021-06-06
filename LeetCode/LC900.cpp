class RLEIterator {
public:
    vector<int> q;
    int k=0;
    RLEIterator(vector<int>& encoding) {
        q = encoding;
    }
    
    int next(int n) {
        while(k < q.size() && n > q[k]) {
            n -= q[k];
            k += 2;
        }
        if(k >= q.size()) return -1;
        q[k] -= n;
        return q[k+1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */