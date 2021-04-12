typedef map<string, int> MPSI;

class Solution {
public:
    MPSI dfs(string& str, int& u) {
        MPSI res;
        while (u < str.size()) {
            if (str[u] == '(') {
                u ++ ;
                auto t = dfs(str, u);
                u ++ ;
                int cnt = 1, k = u;
                while (k < str.size() && isdigit(str[k])) k ++ ;
                if (k > u) {
                    cnt = stoi(str.substr(u, k - u));
                    u = k;
                }
                for (auto& [x, y]: t) res[x] += y * cnt;
            } else if (str[u] == ')') break;
            else {
                int k = u + 1;
                while (k < str.size() && str[k] >= 'a' && str[k] <= 'z') k ++ ;
                auto key = str.substr(u, k - u);
                u = k;
                int cnt = 1;
                while (k < str.size() && isdigit(str[k])) k ++ ;
                if (k > u) {
                    cnt = stoi(str.substr(u, k - u));
                    u = k;
                }
                res[key] += cnt;
            }
        }
        return res;
    }

    string countOfAtoms(string formula) {
        int k = 0;
        auto t = dfs(formula, k);
        string res;
        for (auto& [x, y]: t) {
            res += x;
            if (y > 1) res += to_string(y);
        }
        return res;
    }
};