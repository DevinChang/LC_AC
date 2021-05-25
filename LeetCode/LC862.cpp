class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        typedef long long LL;
        int n = nums.size();
        vector<LL> s(n+1);
        for(int i = 1; i <= n; i++) s[i] = s[i-1] + nums[i-1];
        deque<int> q;
        q.push_back(0);
        int res = INT_MAX;
        for(int i = 1; i <= n; i++) {
            while(q.size() && s[q.front()] + k <= s[i]) {
                res = min(res, i - q.front());
                q.pop_front();
            }
            while(q.size() && s[q.back()] >= s[i]) q.pop_back();
            q.push_back(i);
        } 
        if(res == INT_MAX) res = -1;
        return res; 
    }
};