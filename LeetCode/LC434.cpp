class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') continue;
            int j = i + 1;
            while(j < n && s[j] != ' ') j++;
            res++;
            i = j - 1;
        }
        return res;
    }
};