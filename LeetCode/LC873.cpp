class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> pos;
        for(int i = 0; i < n; i++) pos[arr[i]] = i;
        vector<vector<int>> f(n, vector<int>(n));
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int x = arr[i] - arr[j];
                f[i][j] = 2;
                if(x < arr[j] && pos.count(x)) {
                    int k = pos[x];
                    f[i][j] = max(f[i][j], f[j][k] + 1);
                }
                res = max(res, f[i][j]);
            }
        }
        if (res < 3) return 0;
        return res;
    }
};