class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char,int> hash;
        for(int i = 0; i < S.size(); i++) hash[S[i]] = i;
        sort(T.begin(), T.end(), [&](char a, char b) {
            return hash[a] < hash[b];
        });
        return T;
    }
};