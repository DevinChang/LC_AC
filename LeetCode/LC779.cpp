class Solution {
public:
    int kthGrammar(int N, int K) {
        int res = 0;
        for(; N > 1; N--) {
            if(K > (1 << N - 2)) {
                res ^= 1;
                K -= 1 << N - 2;
            }
        }
        return res;
    }
};