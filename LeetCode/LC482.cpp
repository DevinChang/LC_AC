class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string s;
        for(auto c : S) {
            if(c != '-') s += c;
        }
        string res;
        for(int i = 0; i < s.size() % K; i++) res += toupper(s[i]);
        for(int i = s.size() % K; i < s.size();) {
            if(res.size()) res += '-';
            for(int j = 0; j < K; j++) res += toupper(s[i++]);
        }
        return res;
    }
};