class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hash;
        for(auto c : s) hash[c]++;
        sort(s.begin(), s.end(), [&](char a, char b) {
            if(hash[a] != hash[b]) return hash[a] > hash[b];
            return a < b;
        });
        return s;
    }
};