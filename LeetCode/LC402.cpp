class Solution {
public:
    string removeKdigits(string num, int k) {
        k = min(k, (int)num.size());;
        string res;
        for(auto c : num) {
            while(k && res.size() && res.back() > c) {
                k--;
                res.pop_back();
            }
            res += c;
        }
        while(k--) res.pop_back();
        k = 0;
        while(k < res.size() && res[k] == '0') k++;
        if(k == res.size()) res += '0';
        return res.substr(k);
    }
};