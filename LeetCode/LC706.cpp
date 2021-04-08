const int N = 19997;
typedef pair<int,int> PII;
class MyHashMap {
public:
    vector<PII> h[N];
    /** Initialize your data structure here. */
    MyHashMap() {

    }

    int find(vector<PII>& h, int key) {
        for(int i = 0; i < h.size(); i++) {
            if(h[i].first == key) return i;
        }
        return -1;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int t = key % N;
        int k = find(h[t], key);
        if(k == -1) h[t].push_back({key, value});
        else h[t][k].second = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int t = key % N;
        int k = find(h[t], key);
        if(k == -1) return -1;
        return h[t][k].second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int t = key % N;
        int k = find(h[t], key);
        if(k != -1) h[t].erase(h[t].begin() + k);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */