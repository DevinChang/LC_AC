class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        stack<int> stk;
        vector<int> res(n);
        for(int i = n-1; i >= 0; i--) {
            while(stk.size() && T[i] >= T[stk.top()]) stk.pop();
            if(stk.size()) res[i] = stk.top() - i;
            stk.push(i);
        }
        return res;
    }
};