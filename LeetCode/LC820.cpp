const int N = 2000 * 7 + 10;

int son[N][26], cnt[N], len[N], idx;

class Solution {
public:
    void insert(string& s) {
        reverse(s.begin(), s.end());
        int p = 0;
        for (auto c: s) {
            int u = c - 'a';
            if (!son[p][u]) son[p][u] = ++ idx;
            cnt[p] ++ ;
            p = son[p][u];
        }
        len[p] = s.size();
    }

    int minimumLengthEncoding(vector<string>& words) {
        memset(son, 0, sizeof son);
        memset(cnt, 0, sizeof cnt);
        idx = 0;

        for (auto& w: words) insert(w);
        int res = 0;
        for (int i = 1; i <= idx; i ++ )
            if (!cnt[i])
                res += len[i] + 1;
        return res;
    }
};