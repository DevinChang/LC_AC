class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> res(n, INT_MAX);
        for (int i = 0, j = -1; i < n; i ++ ) {
            if (s[i] == c) j = i;
            if (j != -1) res[i] = i - j;
        }
        for (int i = n - 1, j = -1; i >= 0; i -- ) {
            if (s[i] == c) j = i;
            if (j != -1) res[i] = min(res[i], j - i);
        }
        return res;
    }
};