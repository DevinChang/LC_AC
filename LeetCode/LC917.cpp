class Solution {
public:
    string reverseOnlyLetters(string s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while(i < j && !(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')) i++;
            while(i < j && !(s[j] >= 'a' && s[j] <= 'z' || s[j] >= 'A' && s[j] <= 'Z')) j--;
            if(i < j) swap(s[i], s[j]);
        }
        return s;
    }
};