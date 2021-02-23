class Solution {
public:
    vector<int> s;

    Solution(vector<int>& w) {
        s = w;
        for(int i = 1; i < s.size(); i++) s[i] += s[i-1];
    }
    
    int pickIndex() {
        int x = rand() % s.back() + 1;
        return lower_bound(s.begin(), s.end(), x) - s.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */