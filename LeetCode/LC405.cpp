class Solution {
public:
    string toHex(unsigned int num) {
        if(!num) return "0";
        string res;
        string t = "0123456789abcdef";
        while(num) {
            res += t[num & 0xf];
            num >>= 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};