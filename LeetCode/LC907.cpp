class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> l(n), r(n);
        stack<int> stk;
        for(int i = 0; i < n; i++) {
            while(stk.size() && arr[stk.top()] > arr[i]) stk.pop();
            if(stk.empty()) l[i] = -1;
            else l[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for(int i = n-1; i >= 0; i--) {
            while(stk.size() && arr[stk.top()] >= arr[i]) stk.pop();
            if(stk.empty()) r[i] = n;
            else r[i] = stk.top();
            stk.push(i);
        }

        typedef long long LL;
        const int MOD = 1e9 + 7;
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = (res + (LL)arr[i] * (i - l[i]) * (r[i] - i)) % MOD;
        }
        return res;
    }
};