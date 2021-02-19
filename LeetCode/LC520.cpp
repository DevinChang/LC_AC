class Solution {
public:
    bool check(char c){
        return c >= 'A' && c <= 'Z';
    }

    bool detectCapitalUse(string word) {
        int cnt = 0;
        for(auto c : word) {
            if(check(c)) cnt++;
        }
        return cnt == word.size() || !cnt || cnt == 1 && check(word[0]);
    }
};