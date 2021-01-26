class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        int res = 0;
        for(int i = 1; i < t.size(); i++) res += min(t[i]-t[i-1], d);
        if(t.size()) res += d;
        return res;
    }
};