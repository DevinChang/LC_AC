class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0) return 0;
        vector<int> nums;
        while(n) nums.push_back(n % 10), n /= 10;
        reverse(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            int d = nums[i];
            int l = 0, r = 0, p = 1;
            for(int j = 0; j < i; j++) l = l * 10 + nums[j];
            for(int j = i + 1; j < nums.size(); j++){ 
                r = r * 10 + nums[j];
                p = p * 10;
            }
            // abcdefg, 假如d为第四位，当d=0时，该位置为1的情况为 (000~abc-1)1(000~999),即abc的个数乘以后面的位数
            if(d == 0) res += l * p;
            else if(d == 1) res += l * p + r + 1;
            else res += (l + 1) * p;
        }
        return res;
    }
};