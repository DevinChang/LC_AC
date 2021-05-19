class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> L(n, 1), R(n, 1);
        for (int i = 1; i < n; i ++ )
            if (arr[i] > arr[i - 1])
                L[i] = L[i - 1] + 1;
        for (int i = n - 2; i >= 0; i -- )
            if (arr[i+1] < arr[i])
                R[i] = R[i + 1] + 1;

        int res = 0;
        for (int i = 0; i < n; i ++ )
            if (L[i] > 1 && R[i] > 1)
                res = max(res, L[i] + R[i] - 1);
        return res;
    }
};