class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0, w = 0;
        for(auto c : moves) {
            if(c == 'U') h++;
            else if (c == 'D') h--;
            else if (c == 'L') w++;
            else if (c == 'R') w--;
        }
        return h == 0 && w == 0;
    }
};