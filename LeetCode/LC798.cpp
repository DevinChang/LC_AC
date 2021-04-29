class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n = A.size();
        vector<int> b(n + 1);
        for (int i = 0; i < A.size(); i ++ ) {
            int l = i - A[i] + 1, r = i;
            if (l >= 0) b[l] ++, b[r + 1] -- ;
            else {
                b[0] ++, b[r + 1] -- ;
                b[l + n] ++, b[n] -- ;
            }
        }
        int res = INT_MAX, k = 0;
        for (int i = 0, sum = 0; i < n; i ++ ) {
            sum += b[i];
            if (res > sum) {
                res = sum;
                k = i;
            }
        }
        return k;
    }
};