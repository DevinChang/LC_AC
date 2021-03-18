class MyCircularQueue {
public:
    int hh = 0, tt = 0;
    vector<int> q;

    MyCircularQueue(int k) {
        q.resize(k+1);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        q[tt++] = value;
        if(tt == q.size()) tt = 0;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        hh++;
        if(hh == q.size()) hh = 0;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[hh];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        int t = tt - 1;
        // tt 为队尾，不存元素
        if (t < 0) t = q.size() - 1;
        return q[t];
    }
    
    bool isEmpty() {
        return hh == tt;
    }
    
    bool isFull() {
        return (tt + 1) % q.size() == hh;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */