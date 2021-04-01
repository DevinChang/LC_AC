const int N = 1 << 15;
int f[N], g[N][26];
  
class Solution {
public:
    const int INF = 20;
    int n;
    string target;
    vector<string> strs;

    int fill(int state, char c) {
        auto& v = g[state][c-'a'];
        if(v != -1) return v;
        v = state;
        for(int i = 0; i < n; i++) {
            if(!(state >> i & 1) && target[i] == c) {
                v += 1 << i;
                break;
            }
        }
        return v;
    }

    int dfs(int state) {
        auto& v = f[state];
        if(v != -1) return v;
        if(state == (1 << n) - 1) return v = 0;
        v = INF:
        for(auto& str : strs) {
            int cur = state;
            for(auto c : str) cur = fill(cur, c);
            if(cur != state) v = min(v, dfs(cur)+1);
        }
        return v;
    }

    int minStickers(vector<string>& stickers, string tar) {
        memset(f, -1, sizeof f);
        memset(g, -1, sizeof g);
        target = tar;
        strs = stickers;
        n = target.size();
        int res = dfs(0);
        if(res == INF) res = -1;
        return res;
    }
};