class Solution {
public:
    int findIntegers(int n) {
        vector<int> num;
        // 转换为二进制数组
        while(n) num.push_back(n % 2), n /= 2;
        vector<vector<int>> f(num.size() + 1, vector<int>(2));
        f[1][0] = f[1][1] = 1;
        for(int i = 2; i <= num.size(); i++) {
            f[i][0] = f[i-1][0] + f[i-1][1];
            f[i][1] = f[i-1][0];
        }

        int res = 0;
        for(int i = num.size(), last = 0; i; i--) {
            int x = num[i-1];
            // 如果当前位是1的话，则加上数位为0的结果
            if(x) {
                res += f[i][0];
                // 如果上一位也是1，则不符合要求，输出结果
                if (last) return res;
            }
            last = x;
        }
        // 如果原数据合法，则需要加上1
        return res + 1;
    }
};