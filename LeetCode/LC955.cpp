class Solution {
public:

    int minDeletionSize(vector<string>& A) {
        int n = A.size(), m = A[0].length();
        int ans = 0;
        bool flag;
        vector<bool> end(n, false);

        for (int i = 0; i < m; i++) {

            flag = true;
            for (int j = 0; j < n - 1; j++)
                if (!end[j]) {
                    if (A[j][i] > A[j + 1][i]) {
                        flag = false;
                        break;
                    }
                }

            if (!flag) {
                ans++;
            }
            else {
                for (int j = 0; j < n - 1; j++)
                    if (A[j][i] < A[j + 1][i]) {
                        end[j] = true;
                    }
            }
        }

        return ans;
    }
};