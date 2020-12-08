class Solution {
public:
    int findNthDigit(int n) {
        long long cnt = 1, st = 9, ten = 1;
        // 确定位于哪个区间,[1,9],[10-99],...
        while(n > cnt * st){
            n -= cnt * st;
            cnt++;
            st *= 10, ten *= 10;
        }
        // 确定是区间里的哪个数, n/k下取整等于n-1/k - 1
        ten += (n + cnt - 1) / cnt -1;
        n = n % cnt ? n % cnt : cnt;
        return to_string(ten)[n-1]-'0';
    }
};