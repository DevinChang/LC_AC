class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int res = 0;
        int n = img1.size();
        for (int i = -n; i < n; i ++ )
            for (int j = -n; j < n; j ++ ) {
                int cnt = 0;
                for (int x = max(0, -i); x < min(n, n - i); x ++ )
                    for (int y = max(0, -j); y < min(n, n - j); y ++ )
                        if (img1[i + x][j + y] && img2[x][y])
                            cnt ++ ;
                res = max(res, cnt);
            }
        return res;
    }
};