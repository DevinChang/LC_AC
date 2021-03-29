const int N = 10010;

int son[N][26], idx;
bool is_end[N];

class MagicDictionary {
public:
    void insert(string& s) {
        int p = 0;
        for (auto c: s) {
            int u = c - 'a';
            if (!son[p][u]) son[p][u] = ++ idx;
            p = son[p][u];
        }
        is_end[p] = true;
    }

    /** Initialize your data structure here. */
    MagicDictionary() {
        memset(son, 0, sizeof son);
        idx = 0;
        memset(is_end, 0, sizeof is_end);
    }

    void buildDict(vector<string> dictionary) {
        for (auto& s: dictionary) insert(s);
    }

    bool dfs(string& s, int p, int u, int c) {
        if (is_end[p] && u == s.size() && c == 1) return true;
        if (c > 1 || u == s.size()) return false;

        for (int i = 0; i < 26; i ++ ) {
            if (!son[p][i]) continue;
            if (dfs(s, son[p][i], u + 1, c + (s[u] - 'a' != i)))
                return true;
        }
        return false;
    }

    bool search(string searchWord) {
        return dfs(searchWord, 0, 0, 0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */