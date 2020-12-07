class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        typedef long long LL;
        LL sum = 0, cur = 0;
        for(auto c : A) sum += c;
        int n = A.size();
        for(int i = 0; i < n; i++) cur += i * A[i];
        LL res = cur;
        for(int i = n - 1; i >= 0; i --) {
            cur += sum - (LL)n * A[i];
            res = max(res, cur);
        }
        return res;
    }
};