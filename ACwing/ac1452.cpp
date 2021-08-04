// Forward declaration of queryAPI.
// int query(int x, int y);
// return int means matrix[x][y].

class Solution {
public:
    vector<int> getMinimumValue(int n) {
        typedef long long LL;
        const LL INF = 1e15;

        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;

            int k;
            LL val = INF;
            for (int i = 0; i < n; i ++ )
            {
                int t = query(i, mid);
                if (t < val)
                {
                    val = t;
                    k = i;
                }
            }

            LL left = mid ? query(k, mid - 1) : INF;
            LL right = mid + 1 < n ? query(k, mid + 1) : INF;

            if (val < left && val < right) return {k, mid};
            if (left < val) r = mid - 1;
            else l = mid + 1;
        }

        int k;
        LL val = INF;
        for (int i = 0; i < n; i ++ )
        {
            int t = query(i, r);
            if (t < val)
            {
                val = t;
                k = i;
            }
        }

        return {k, r};
    }
};