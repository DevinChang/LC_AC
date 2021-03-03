class Solution {
public:
    bool checkRecord(string s) {
        bool L = false;
        for(int i = 0, A = 0; i < s.size(); i++) {
            if(s[i] == 'A') A++;
            else if (i >= 2 && s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L') L = true;
            if(A > 1 || L) return false;
        }
        return true;
    }
};