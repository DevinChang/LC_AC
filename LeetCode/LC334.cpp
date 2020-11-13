class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> q(2, INT_MAX);
        for(auto a : nums){
            int k = 2;
            while(k > 0 && q[k-1] >= a) k--;
            if(k == 2) return true;
            q[k] = a;
        }
        return false;
    }
};