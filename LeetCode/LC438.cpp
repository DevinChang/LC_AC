class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> hash;
        for(auto c : p) hash[c]++;
        vector<int> res;
        int n = s.size(), t = hash.size(), pn = p.size();
        for(int i = 0, j = 0, k = 0; i < n; i++) {
            if(--hash[s[i]] == 0) k++;
            while(i - j + 1 > pn) {
                if(hash[s[j]] == 0) k--;
                hash[s[j++]]++;
            }
            if(k == t) res.push_back(j);
        }
        return res;
    }
};