class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 31; i++){
            int x = 0, y = 0;
            for(auto n : nums) {
                if(n >> i & 1) y++;
                else x++;
            }
            res += x * y;
        }
        return res;
    }
};