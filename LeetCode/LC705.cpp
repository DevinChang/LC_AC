const int N = 19997;
class MyHashSet {
public:
    vector<int> h[N];
    /** Initialize your data structure here. */
    MyHashSet() {

    }
    
    int find(vector<int>& h, int key) {
        for(int i = 0; i < h.size(); i++) {
            if(h[i] == key) return i;
        }
        return -1;
    }

    void add(int key) {
        int t = key % N;
        int k = find(h[t], key);
        if(k == -1) h[t].push_back(key); 
    }
    
    void remove(int key) {
        int t = key % N;
        int k = find(h[t], key);
        if(k != -1) h[t].erase(h[t].begin() + k);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int t = key % N;
        int k = find(h[t], key);
        return k != -1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */