class Solution {
public:
    string decodeString(string s){
        int u = 0;
        return dfs(s, u);
    }

    string dfs(string &s, int &u){
        string res;
        while(u < s.size() && s[u] != ']') {
            if(s[u] >= 'a' && s[u] <= 'z' || s[u] >= 'A' && s[u] <= 'Z') res += s[u++];
            if(s[u] >= '0' && s[u] <= '9') {
                int k = u;
                while(s[k] >= '0' && s[k] <= '9') k++;
                int x = stoi(s.substr(u, k - u));
                u = k + 1; // 去掉左括号
                string y = dfs(s, u);
                u++; // 去掉右括号
                while(x--) res += y; // 有x个重复的y
            }
        }
        return res;
    }
};