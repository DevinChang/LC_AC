class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        string res;
        for(int i = n - 1, sum = 0; i >= 0; i--) {
            sum = (sum +shifts[i]) % 26;
            res += (s[i] - 'a' + sum) % 26 + 'a';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};