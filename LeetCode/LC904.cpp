class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0;
        unordered_map<int,int> cnt;
        for(int i = 0, j = 0, s = 0; i < tree.size();i++) {
            if(++cnt[tree[i]] == 1) s++;
            while(s > 2) {
                if(--cnt[tree[j]] == 0) s--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};