class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        vector<int> S(121);
        for(int i = 0; i < n; i++) S[ages[i]]++;
        int res = n * n;
        for(int i = 0; i <= 120; i++) {
            for(int j = 0; j <= 120; j++) {
                if(j <= 0.5 * i + 7 || j > i) res -= S[i] * S[j];
                else if(i == j) res -= S[i];
            }
        }
        return res;
    }
};