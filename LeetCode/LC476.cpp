class Solution {
public:
    int findComplement(int num) {
        if(!num) return 1;
        int cnt = 0;
        for(int x = num; x; x>>=1) cnt++;
        return ~num & ((1ll << cnt) -1 );
    }
};