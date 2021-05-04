class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int r = 0, c = 0;
        for(auto& x : s){
            int w = widths[x-'a'];
            if(c+w > 100) r++, c = 0;
            c += w;
        }
        return {r+1, c};
    }
};