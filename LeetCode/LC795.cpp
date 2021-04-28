class Solution {
public:
    int calc(vector<int>& A, int k) {
        int res = 0;
        for(int i = 0; i < A.size();i++) {
            if(A[i] > k) continue;
            int j = i + 1;
            while(j < A.size() && A[j] <= k) j++;
            int z = j - i;
            res += z * (z + 1) / 2;
            i = j;
        }
        return res;
    }
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return calc(A, R) - calc(A, L-1);
    }
};