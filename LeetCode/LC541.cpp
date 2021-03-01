class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0; i < n; i += 2 * k) {
            int l = i, r = min(i + k, n);
            reverse(s.begin()+l, s.begin() + r);
        }
        return s;
    }
};