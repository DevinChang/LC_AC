class Solution {
public:
    string convertToBase7(int num) {
        if(!num) return "0";
        bool is_neg = false;
        if(num < 0) {
            is_neg = true;
        }
        num = abs(num);
        string res;
        while(num) {
            res += to_string(num % 7);
            num /= 7;
        }
        reverse(res.begin(), res.end());
        if(is_neg) res = "-" + res;
        return res;
    }
};