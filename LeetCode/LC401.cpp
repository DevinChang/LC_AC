class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        char s[10];
        for(int h = 0; h < 12; h++) {
            for(int m = 0; m < 60; m++){
                int cnt = 0;
                for(int i = 0; i < 4; i++){
                    if(((h >> i) & 1) == 1) cnt++;
                }
                for(int i = 0; i < 6; i++){
                    if(((m >> i) & 1) == 1) cnt++;
                }
                if (cnt == num) {
                    sprintf(s, "%d:%02d", h, m);
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};