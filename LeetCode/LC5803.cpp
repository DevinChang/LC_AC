typedef unsigned long long ULL;
const int N = 100010;

ULL h[N], p[N];

ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

class Solution {
public:
    vector<vector<int>> paths;
    unordered_map<ULL, int> cnt, S;

    bool check(int mid) {
        cnt.clear(), S.clear();
        p[0] = 1;
        int k = 0;
        for (auto& str: paths) {
            int n = str.size();
            for (int i = 1; i <= n; i ++ )
            {
                p[i] = p[i - 1] * 133331;
                h[i] = h[i - 1] * 133331 + str[i - 1];
            }
            for (int i = mid; i <= n; i ++ ) {
                auto t = get(i - mid + 1, i);
                if (!S.count(t) || S[t] != k) {
                    S[t] = k;
                    cnt[t] ++ ;
                }
            }
            k ++ ;
        }
        int res = 0;
        for (auto& [k, v]: cnt) res = max(res, v);
        return res == paths.size();
    }

    int longestCommonSubpath(int n, vector<vector<int>>& _paths) {
        paths = _paths;
        int l = 0, r = N;
        for (auto& p: paths) {
            r = min(r, (int)p.size());
        }

        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return r;
    }
};