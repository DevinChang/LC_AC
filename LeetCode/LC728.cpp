class Solution {
public:
    bool check(int num) {
        for(auto c : to_string(num)) {
            if(c == '0' || num % (c - '0')) return false;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; i++) {
            if(check(i)) res.push_back(i);
        }
        return res;
    }
};