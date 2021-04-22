class Solution {
public:
    int n;
    vector<vector<int>> g;
    vector<vector<bool>> st;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    bool dfs(int x, int y, int mid) {
        if (x == n - 1 && y == n - 1) return true;
        st[x][y] = true;
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < n && g[a][b] <= mid && !st[a][b])
                if (dfs(a, b, mid)) return true;
        }
        return false;
    }

    bool check(int mid) {
        if (g[0][0] > mid) return false;
        st = vector<vector<bool>>(n, vector<bool>(n));
        return dfs(0, 0, mid);
    }

    int swimInWater(vector<vector<int>>& grid) {
        g = grid;
        n = g.size();
        int l = 0, r = n * n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};