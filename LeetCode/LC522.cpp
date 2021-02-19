class Solution {
public:
    bool check(string a, string b) {
        int k = 0;
        int n = a.size();
        for(auto c : b) {
            if(k < n && c == a[k]) k++;
        }
        return k == n;
    }

    int findLUSlength(vector<string>& strs) {
        int res = -1;
        int n = strs.size();
        for(int i = 0; i < n; i++) {
            bool is_sub = false;
            for(int j = 0; j < n; j++) {
                if(i != j && check(strs[i], strs[j])){
                    is_sub = true;
                    break;
                }
            }
            if(!is_sub) res = max(res, (int)strs[i].size());
        }
        return res;
    }
};