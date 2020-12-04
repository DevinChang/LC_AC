class Solution {
public:
    char findTheDifference1(string s, string t) {
        unordered_map<char, int> hash;
        for(auto c : t) hash[c]++;
        for(auto c : s) hash[c]--;
        for(auto c : t) {
            if(hash[c]) return c;
        }
        return -1;
    }
    char findTheDifference(string s, string t) {
        int x = 0;
        for(auto c : s) x ^= c;
        for(auto c : t) x ^= c;
        return x;
    }
};