class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int tot = 0;
        for(int x : nums) tot ^= x;
        if(tot == 0) return true;
        return nums.size() % 2 == 0;
    }
};