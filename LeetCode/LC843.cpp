/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int n;
    vector<vector<int>> f;
    vector<bool> st;

    int get(int j, int u) {
        int res = 0;
        for (int i = 0; i < n; i ++ )
            if (!st[i] && f[j][i] == u)
                res ++ ;
        return res;
    }

    void findSecretWord(vector<string>& ws, Master& master) {
        n = ws.size();
        f = vector<vector<int>>(n, vector<int>(n));
        st = vector<bool>(n);
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                for (int k = 0; k < 6; k ++ )
                    if (ws[i][k] == ws[j][k])
                        f[i][j] ++ ;

        for (int i = 0; i < 10; i ++ ) {
            int k = -1, w = INT_MAX;
            for (int j = 0; j < n; j ++ ) {
                if (st[j]) continue;
                int t = 0;
                for (int u = 0; u <= 6; u ++ )
                    t = max(t, get(j, u));
                if (w > t) k = j, w = t;
            }
            int res = master.guess(ws[k]);
            if (res == 6) break;
            st[k] = true;
            for (int j = 0; j < n; j ++ )
                if (f[k][j] != res)
                    st[j] = true;
        }
    }
};