const int N = 2510;

int son[N][26], V[N], S[N], idx;

class MapSum {
public:
    void add(string& s, int value, int last) {
        int p = 0;
        for (auto c: s) {
            int u = c - 'a';
            if (!son[p][u]) son[p][u] = ++ idx;
            p = son[p][u];
            S[p] += value - last;
        }
        V[p] = value;
    }

    int query(string& s) {
        int p = 0;
        for (auto c: s) {
            int u = c - 'a';
            if (!son[p][u]) return 0;
            p = son[p][u];
        }
        return p;
    }

    /** Initialize your data structure here. */
    MapSum() {
        memset(son, 0, sizeof son);
        idx = 0;
        memset(V, 0, sizeof V);
        memset(S, 0, sizeof S);
    }

    void insert(string key, int val) {
        add(key, val, V[query(key)]);
    }

    int sum(string prefix) {
        return S[query(prefix)];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */