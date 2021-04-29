class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size(), INF = 1e8;
        vector<vector<int>> f(n, vector<int>(2, INF));
        f[0][0] = 0, f[0][1] = 1;
        for(int i = 1; i < n; i++) {
            if(A[i] > A[i-1] && B[i] > B[i-1]) f[i][0] = min(f[i][0], f[i-1][0]);
            if(A[i] > B[i-1] && B[i] > A[i-1]) f[i][0] = min(f[i][0], f[i-1][1]);
            if(B[i] > A[i-1] && A[i] > B[i-1]) f[i][1] = min(f[i][1], f[i-1][0]+1);
            if(B[i] > B[i-1] && A[i] > A[i-1]) f[i][1] = min(f[i][1], f[i-1][1]+1);
        }
        return min(f[n-1][0],f[n-1][1]);
    }
};