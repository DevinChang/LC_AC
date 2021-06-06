class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            string res = s;
            for(int i = 0; i < s.size(); i++) {
                s = s.substr(1) + s[0];
                res = min(res, s);
            }
            return res;
        }
        sort(s.begin(), s.end());
        return s;
    }
};