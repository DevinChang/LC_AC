class Solution {
public:
    int n, len;
    unordered_map<int,int> hash;

    Solution(int N, vector<int>& blacklist) {
        n = N, len = blacklist.size();
        unordered_set<int> S;
        for(int i = n - len; i < n; i++) S.insert(i);
        for(auto x : blacklist) S.erase(x);
        auto it = S.begin();
        for(auto x : blacklist) {
            if (x < n - len) hash[x] = *it++;
        }
    }
    
    int pick() {
        int k = rand() % (n - len);
        if(hash.count(k)) return hash[k];
        return k;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */