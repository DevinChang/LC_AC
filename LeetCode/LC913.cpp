const int N = 210;

int f[2 * N][N][N];

class Solution {
public:
    int n;
    vector<vector<int>> g;

    int dp(int k, int i, int j) {
        int& v = f[k][i][j];
        if (v != -1) return v;
        if (k > n * 2) return v = 0;
        if (!i) return v = 1;
        if (i == j) return v = 2;

        if (k % 2 == 0) {  // 该老鼠走了
            int draws = 0;
            for (int x: g[i]) {
                int t = dp(k + 1, x, j);
                if (t == 1) return v = 1;
                if (!t) draws ++ ;
            }
            if (draws) return v = 0;
            return v = 2;
        } else {  // 该猫走了
            int draws = 0;
            for (int x: g[j]) {
                if (!x) continue;
                int t = dp(k + 1, i, x);
                if (t == 2) return v = 2;
                if (!t) draws ++ ;
            }
            if (draws) return v = 0;
            return 1;
        }
    }

    int catMouseGame(vector<vector<int>>& graph) {
        g = graph;
        n = g.size();
        memset(f, -1, sizeof f);
        return dp(0, 1, 2);
    }
};