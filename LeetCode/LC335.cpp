class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        if(n <= 3) return false;
        for(int i = 3; i < n; i++){
            if(x[i-1] <= x[i-3] && x[i] >= x[i-2]) return true;
            if(i >= 4 && x[i-3] == x[i-1] && x[i] + x[i-4] >= x[i-2]) return true;
            if (i >= 5 && x[i - 3] >= x[i - 1] && x[i - 1] + x[i - 5] >= x[i - 3] && x[i - 2] >= x[i - 4] && x[i - 4] + x[i] >= x[i - 2]) return true;
        }
        return false;
    }
};