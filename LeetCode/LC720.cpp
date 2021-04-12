const int N = 30010;

int son[N][26], idx;
int id[N];

class Solution {
public:
    void insert(string& str, int k) {
        int p = 0;
        for (auto c: str) {
            int u = c - 'a';
            if (!son[p][u]) son[p][u] = ++ idx;
            p = son[p][u];
        }
        id[p] = k;
    }

    vector<int> dfs(int p, int len) {
        vector<int> res{len, id[p]};
        for (int i = 0; i < 26; i ++ ) {
            int j = son[p][i];
            if (j && id[j] != -1) {
                auto t = dfs(j, len + 1);
                if (res[0] < t[0]) res = t;
            }
        }
        return res;
    }

    string longestWord(vector<string>& words) {
        memset(id, -1, sizeof id);
        memset(son, 0, sizeof son);
        idx = 0;
        for (int i = 0; i < words.size(); i ++ ) insert(words[i], i);
        auto t = dfs(0, 0);
        if (t[1] != -1) return words[t[1]];
        return "";
    }
};