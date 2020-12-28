class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); i++) {
            unordered_map<int,int> cnt;
            for(int j = 0; j < points.size(); j++) {
                if(i != j) {
                    int dx = points[i][0] - points[j][0];
                    int dy = points[i][1] - points[j][1];
                    int dist = dx * dx + dy * dy;
                    cnt[dist]++;
                }
            }
            for(auto [d,c] : cnt) res += c * (c - 1);
        }
        return res;
    }
};