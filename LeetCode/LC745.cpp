const int N = 2000000;
int son[N][27], w[N], idx;
class WordFilter {
public:
    void insert(string& s, int id) {
        int p = 0;
        for(auto c : s) {
            int t = c == '#' ? 26 : c - 'a';
            if(!son[p][t]) son[p][t] = ++idx;
            p = son[p][t];
            w[p] = id;
        }
    }

    int query(string s) {
        int p = 0;
        for(auto c : s) {
            int t = c == '#' ? 26 : c - 'a';
            if(!son[p][t]) return -1;
            p = son[p][t];
        }
        return w[p];
    }

    WordFilter(vector<string>& words) {
        memset(son, 0, sizeof son);
        idx = 0;
        for(int i = 0; i < words.size(); i++) {
            string s = '#' + words[i];
            insert(s, i);
            for(int j = words[i].size() - 1; j >= 0; j --) {
                s = words[i][j] + s;
                insert(s, i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return query(suffix+'#'+prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */