class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int j = i + 1;
            while(j < n && s[i] == s[j]) j++;
            if((j - i) >= 3) res.push_back({i, j-1});
            i = j - 1;
        }
        return res;
    }
};