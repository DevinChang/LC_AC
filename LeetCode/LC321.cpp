class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<int> res(k, INT_MIN);
        for(int i = max(0, k - m); i <= k && i <= n; i++){
            auto a = maxArray(nums1, i);
            auto b = maxArray(nums2, k - i);
            auto c = merge(a, b);
            res = max(res, c);
        }
        return res;
    }

    vector<int> maxArray(vector<int> &nums, int k){
        vector<int> res(k);
        int n = nums.size();
        for(int i = 0, j = 0; i < n; i++){
            int a = nums[i];
            while(j && res[j-1] < a && n - i + j > k) j--;
            if(j < k) res[j++] = a;
        }
        return res;
    }

    vector<int> merge(vector<int> &nums1, vector<int> &nums2){
        vector<int> res;
        deque<int> q1(nums1.begin(), nums1.end());
        deque<int> q2(nums2.begin(), nums2.end());
        int n = nums1.size(), m = nums2.size();
        while(!q1.empty() && !q2.empty()){
            if(q1 < q2){
                res.push_back(q2.front());
                q2.pop_front();
            }
            else {
                res.push_back(q1.front());
                q1.pop_front();
            }
        }
        while(!q1.empty()){
            res.push_back(q1.front());
            q1.pop_front();
        }
        while(!q2.empty()){
            res.push_back(q2.front());
            q2.pop_front();
        }
        return res;
    }
};