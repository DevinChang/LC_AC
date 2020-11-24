class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& w) {
        if (w.empty()) return {};
        sort(w.begin(), w.end());
        int n = w.size();
        vector<int> f(n);

        int k = 0;
        for (int i = 0; i < n; i ++ ) {
            f[i] = 1;
            for (int j = 0; j < i; j ++ )
                if (w[i] % w[j] == 0)
                    f[i] = max(f[i], f[j] + 1);
            if (f[k] < f[i]) k = i;
        }

        vector<int> res(1, w[k]);
        while (f[k] > 1) {
            for (int i = 0; i < k; i ++ )
                if (w[k] % w[i] == 0 && f[k] == f[i] + 1) {
                    res.push_back(w[i]);
                    k = i;
                    break;
                }
        }
        return res;
    }
};