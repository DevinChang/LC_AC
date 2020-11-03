class Solution {
public:
    vector<string> ans;

    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for(auto c : s){
            if(c == '(') l++;
            else if(c == ')'){
                if(l == 0) r++;
                else l--;
            }
        }
        dfs(s, 0, "", 0, l, r);
        return ans;
    }

    void dfs(string &s, int u, string path, int cnt, int l, int r){
        if(u == s.size()){
            if (cnt == 0) ans.push_back(path);
            return;
        }
        if(s[u] != '(' && s[u] != ')') dfs(s, u+1, path+s[u], cnt, l, r);
        else if (s[u] == '('){
            int k = u;
            while(s[k] == '(') k++;
            l -= k - u;
            for(int i = k -u; i >= 0; i--){
                if(l >= 0) dfs(s, k, path, cnt, l, r);
                path += '(';
                cnt++, l++;
            }
        } else if (s[u] == ')'){
            int k = u;
            while(s[k] == ')') k++;
            r -= k - u;
            for(int i = k - u; i >= 0; i--){
                if(cnt >= 0 && r >= 0) dfs(s, k, path, cnt, l, r);
                path += ')';
                cnt--, r++;
            }
        }
    }
};