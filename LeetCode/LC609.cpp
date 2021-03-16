class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(!n) return true;
        int res = 0;
        int len = flowerbed.size();
        for(int i = 0; i < len; i++) {
            if(flowerbed[i]) continue;
            int j = i;
            // 当左右边界都是1，内部有连续的0，这时可以插入位置的数量为: k / 2 -1 
            // 当左右边界只有一个1，即0也是一个边界下，这时可以插入位置的数量为: k / 2
            // 当坐右边界没有1，即0是左右边界的情况下，这时可以插入位置的数量为: k / 2 + 1
            while(j < len && flowerbed[j] == 0) j++;
            int k = j - i -1;
            // 左边界
            if(i == 0) k++;
            // 右边界
            if(j == len) k++;
            res += k / 2;
            if(res >= n) return true;
            i = j;
        }
        return false;
    }
};