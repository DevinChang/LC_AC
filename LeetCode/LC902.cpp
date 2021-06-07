class Solution {
public:
    int power(int a, int b) {
        int res = 1;
        while(b--) res *= a;
        return res;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string num = to_string(n);
        reverse(num.begin(), num.end());
        int res = 0;
        for(int i = 1; i < num.size(); i++) res += power(digits.size(), i);

        bool flag = true;
        for(int i = num.size()-1; i >= 0; i--) {
            int x = num[i] - '0', t = power(digits.size(), i);
            int j;
            for(j = 0; j < digits.size(); j++) {
                if(digits[j][0] - '0' < x) res += t;
                else break;
            }
            if(j < digits.size() && digits[j][0] - '0' == x) continue;
            flag = false;
            break;
        }
        if(flag) res++;
        return res;
    }
};