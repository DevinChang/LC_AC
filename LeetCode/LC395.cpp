class Solution {
public:
    int K;
    unordered_map<char, int> cnt;

    void add (char c, int &x, int &y) {
        if(!cnt[c]) x++;
        cnt[c]++;
        if(cnt[c] == K) y++;
    }

    void del(char c, int &x, int &y) {
        if(cnt[c] == K) y--;
        cnt[c]--;
        if(!cnt[c]) x--;
    }

    int longestSubstring(string s, int _K) {
        K = _K;
        int res = 0;
        for(int k = 1; k <= 26; k++){
            cnt.clear();
            // x表示不同字符的数量，y表示满足要求的字符数量
            for(int i = 0, j = 0, x = 0, y = 0; i < s.size(); i++){ 
                add(s[i], x, y);
                while(x > k) del(s[j++], x, y);
                if(x == y) res = max(res, i - j + 1);
            }
        }
        return res;
    }
};