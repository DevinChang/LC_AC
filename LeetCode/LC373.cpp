class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        if(n < 1 || m < 1 || k < 0) return {};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        for(int i = 0; i < min(k, m); i++){
            heap.push({nums1[0] + nums2[i], 0, i});
        }
        vector<vector<int>> res;
        while(!heap.empty()) {
            if(res.size() == k) return res;
            auto t = heap.top();
            heap.pop();
            res.push_back({nums1[t[1]], nums2[t[2]]});
            if(t[1] + 1 < n) heap.push({nums1[t[1]+1]+nums2[t[2]], t[1]+1, t[2]});
        }
        return res;
    }
};