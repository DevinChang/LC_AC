class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        typedef vector<int> VI;
        VI res;
        priority_queue<VI, vector<VI>, greater<VI>> heap;
        int maxv = INT_MIN;
        for (int i = 0; i < nums.size(); i ++ ) {
            heap.push({nums[i][0], i, 0});
            maxv = max(maxv, nums[i][0]);
        }
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            int l = t[0], r = maxv;
            if (res.empty() || res[1] - res[0] > r - l)
                res = {l, r};
            int i = t[1], j = t[2] + 1;
            if (j < nums[i].size()) {
                heap.push({nums[i][j], i, j});
                maxv = max(maxv, nums[i][j]);
            } else break;
        }
        return res;
    }
};
