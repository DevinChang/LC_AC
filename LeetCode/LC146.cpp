class LRUCache {
    typedef pair<int, int> PII;
    list<PII> lst;
    unordered_map<int, list<PII>::iterator> ihash;
    int cap, count;
public:
    LRUCache(int capacity) : cap(capacity), count(0) {}
    
    int get(int key) {
        int res = -1;
        if(ihash.count(key)){
            res = ihash[key]->second;
            lst.erase(ihash[key]);
            lst.push_front({key, res});
            ihash[key] = lst.begin();
        }
        return res;
    }
    
    void put(int key, int value) {
        if(ihash.count(key)){
            lst.erase(ihash[key]);
        }
        else if(count == cap){
            auto k = lst.back().first;
            lst.pop_back();
            ihash.erase(k);
        }
        else count++;
        lst.push_front({key, value});
        ihash[key] = lst.begin();
    }
};