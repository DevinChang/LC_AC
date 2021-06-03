class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int x, int y) {
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        vector<vector<int>> res;
        res.push_back({x, y});
        int d = 0, tot = rows * cols;
        // 枚举长度
        for (int k = 1; res.size() < tot; k ++ )
            // 每个长度枚举两次
            for (int i = 0; i < 2 && res.size() < tot; i ++ ) {
                for (int j = 0; j < k && res.size() < tot; j ++ ) {
                    int a = x + dx[d], b = y + dy[d];
                    if (a >= 0 && a < rows && b >= 0 && b < cols)
                        res.push_back({a, b});
                    x = a, y = b;
                }
                d = (d + 1) % 4;
            }
        return res;
    }
};