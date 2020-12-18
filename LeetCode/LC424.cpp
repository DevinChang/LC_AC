class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int n = s.size();
        for(int c = 'A'; c <= 'Z'; c++) {
            int cnt = 0;
            for(int i = 0, j = 0; i < n; i++){
                if(s[i] == c) cnt++;
                while(i - j + 1 - cnt > k) {
                    if(s[j] == c) cnt--;
                    j++;
                }
                res = max(res, i - j + 1);
            }
        }
        return res;
    }
};