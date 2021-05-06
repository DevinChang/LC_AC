class Solution {
public:
    int cross(int x1, int y1, int x2, int y2) {
        return x1 * y2 - x2 * y1;
    }
    int area(vector<int>&a, vector<int>& b, vector<int>& c) {
        return cross(b[0]-a[0], b[1]-a[1], c[0]-a[0], c[1]-a[1]);
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int res = 0;
        for(auto& a : points) {
            for(auto& b : points) {
                for(auto& c : points) {
                    res = max(res, abs(area(a, b, c)));
                }
            }
        }        
        return res / 2.0;
    }
};