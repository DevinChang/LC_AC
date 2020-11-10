class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();        
        for(int i = 0, j = 0, k = n-1; i <= k;){
            if(nums[i] == 0) swap(nums[i++], nums[j++]);
            else if(nums[i] == 2) swap(nums[i], nums[k--]);
            else i++;
        }
    }
};