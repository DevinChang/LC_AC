class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        int Base = 10000;
        for(int i = 0; i < n; i++) {
            if(nums[i] >= Base) continue;
            int S = Base + i;
            int k = i, t = nums[k] > 0, last = -1;
            do {
                int p = ((k + nums[k]) % n + n) % n;
                last = nums[k];
                nums[k] = S;
                k = p;
            }while(k != i && nums[k] < Base && (t ^ (nums[k] > 0)) == 0);
            if(last % n && nums[k] == S) return true;
        }
        return false;
    }
};