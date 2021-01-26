class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n2 = nums2.size();
        vector<int> q(n2);
        for(int i = n2-1; i >= 0; i--) {
            int x = nums2[i];
            while(st.size() && x >= st.top()) st.pop();
            if(st.empty()) q[i] = -1;
            else q[i] = st.top();
            st.push(x);
        }
        unordered_map<int, int> hash;
        for(int i = 0; i < n2; i++) hash[nums2[i]] = i;
        vector<int> res;
        for(auto x : nums1) res.push_back(q[hash[x]]);
        return res;
    }
};