class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> heap;
    int k;

    KthLargest(int _k, vector<int>& nums) {
        k = _k;
        for(auto x : nums) {
            heap.push(x);
            if(heap.size() > k) heap.pop();
        }
    }
    
    int add(int val) {
        heap.push(val);
        if(heap.size() > k) {
            heap.pop();
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */