class Solution {
public:
    string s = "aeiou";

    bool check(char c) {
        return s.find(tolower(c)) != -1;
    }

    string reverseVowels(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i ++ , j -- ) {
            while (i < j && !check(s[i])) i ++ ;
            while (i < j && !check(s[j])) j -- ;
            swap(s[i], s[j]);
        }
        return s;
    }
};