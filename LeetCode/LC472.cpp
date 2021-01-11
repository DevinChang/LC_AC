class Solution {
public:
    unordered_set<string> hash;

    bool check(const string &s) {
        int L = s.size();
        vector<int> f(L+1, INT_MIN);
        f[0] = 0;
        for(int i = 0; i < L; i++) {
            if(f[i] < 0) continue;
            for(int j = L; j > i; j--) {
                if(hash.find(s.substr(i, j - i)) != hash.end()) f[j] = f[i] + 1;
                if(f[L] > 1) return true;
            }
        }
        return f[L] > 1;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        for(string &w : words) hash.insert(w);
        for(const string &w : words) {
            if(check(w)) res.push_back(w);
        }
        return res;
    }
};