class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hash;
        for(auto c : s) hash[c]++;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(hash[s[i]] == 1) return i;
        }
        return -1;
    }
};