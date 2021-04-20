class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        auto b = a;
        sort(b.begin(), b.end());
        unordered_map<int,int> cnt;
        int res = 0;
        for(int i = 0, s = 0; i < a.size(); i++) {
            if(cnt[a[i]] == 1) s--;
            else if(cnt[a[i]] == 0) s++;
            cnt[a[i]]--;
            if(cnt[b[i]] == -1) s--;
            else if(cnt[b[i]] == 0) s++;
            cnt[b[i]]++;
            if(!s) res++;
        }
        return res;
    }
};