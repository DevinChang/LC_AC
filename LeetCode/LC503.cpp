class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        stack<int> st;
        vector<int> res(n);
        for(int i = n * 2 - 1; i >= 0; i--) {
            int x = nums[i];
            while(st.size() && x >= st.top()) st.pop();
            if(i < n) {
                if(st.empty()) res[i] = -1;
                else res[i] = st.top();
            }
            st.push(x);
        }
        return res;
    }
};