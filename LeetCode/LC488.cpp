class Solution {
public:
    unordered_map<string, int> f;
    unordered_map<char, int> cnt;
    int ans = 6;

    int findMinStep(string board, string hand) {
        for (auto c: hand) cnt[c] ++ ;
        f[board] = 0;
        dfs(board, get());
        if (ans == 6) ans = -1;
        return ans;
    }

    string clean_up(string s) {
        bool is_changed = true;
        while (is_changed) {
            is_changed = false;
            for (int i = 0; i < s.size(); i ++ ) {
                int j = i + 1;
                while (j < s.size() && s[j] == s[i]) j ++ ;
                if (j - i >= 3) {
                    s = s.substr(0, i) + s.substr(j);
                    is_changed = true;
                    break;
                }
            }
        }
        return s;
    }

    string get() {
        string res;
        for (auto [x, c]: cnt) res += to_string(c);
        return res;
    }

    int h(string board) {  // 至少还需要多少次操作
        sort(board.begin(), board.end());
        int res = 0;
        for (int i = 0; i < board.size();) {
            int j = i + 1;
            while (j < board.size() && board[j] == board[i]) j ++ ;
            if (j - i + cnt[board[i]] < 3) return 6;
            if (j - i <= 2) res += 3 - (j - i);
            i = j;
        }
        return res;
    }

    void dfs(string board, string hand) {
        if (f[board + ' ' + hand] + h(board) >= ans) return;
        for (auto [x, c]: cnt) {
            if (c) {
                -- cnt[x];
                for (int i = 0; i <= board.size(); i ++ ) {
                    auto r = clean_up(board.substr(0, i) + x + board.substr(i));
                    auto s = r + ' ' + get();
                    if (f.count(s) == 0 || f[s] > f[board + ' ' + hand] + 1) {
                        f[s] = f[board + ' ' + hand] + 1;
                        if (r.empty()) ans = min(ans, f[s]);
                        dfs(r, get());
                    }
                }
                ++ cnt[x];
            }
        }
    }
};
