class Solution {
public:
    int binaryGap(int n) {
        int res = 0, last = -1;
        for(int i = 0; i < 30; i++){
            if(n >> i & 1) {
                if(last != -1) res = max(res, i - last);
                last = i;
            }
        }
        return res;
    }
};