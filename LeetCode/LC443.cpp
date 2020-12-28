class Solution {
public:
    int compress(vector<char>& chars) {
        int k = 0;
        int n = chars.size();
        for(int i = 0; i < n; i++) {
            int j = i + 1;
            while(j < n && chars[i] == chars[j]) j++;
            int len = j - i;
            chars[k++] = chars[i];
            if(len > 1) {
                int t = k;
                while(len) {
                    chars[t++] = '0' + len % 10;
                    len /= 10;
                }
                reverse(chars.begin() + k, chars.begin() + t);
                k = t;
            }
            i = j - 1;
        }
        return k;
    }
};