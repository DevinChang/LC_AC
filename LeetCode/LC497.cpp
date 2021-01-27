class Solution {
public:
    int n;
    vector<vector<int>> rects;
    vector<int> s;

    Solution(vector<vector<int>>& _rects) {
        rects = _rects;
        n = rects.size();
        // 计算矩阵的前缀和
        s.push_back(0);
        for(auto &r : rects) {
            int dx = r[2] - r[0] + 1;
            int dy = r[3] - r[1] + 1;
            s.push_back(s.back() + dx * dy);
        }
    }
    
    vector<int> pick() {
        int k = rand() % s.back() + 1;
        // 二分查找当前k落在哪个矩形上面
        int l = 1, r = n;
        while(l < r) {
            int mid = l + r >> 1;
            if(s[mid] >= k) r = mid;
            else l = mid + 1;
        }
        auto &t = rects[r-1];
        int dx = t[2] - t[0] + 1, dy = t[3] - t[1] + 1;
        return {rand() % dx + t[0], rand() % dy + t[1]};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */