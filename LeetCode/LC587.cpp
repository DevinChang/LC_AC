class Solution {
public:
    int cross(int x1, int y1, int x2, int y2) {
        return x1 * y2 - x2 * y1;
    }

    int area(vector<int>& a, vector<int>& b, vector<int>& c) {
        return cross(b[0] - a[0], b[1] - a[1], c[0] - a[0], c[1] - a[1]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        vector<bool> used(n);
        vector<int> hull(n + 2);
        int top = 0;
        for (int i = 0; i < n; i ++ ) {
            while (top >= 2 && area(points[hull[top - 1]], points[hull[top]], points[i]) > 0)
                used[hull[top -- ]] = false;
            hull[ ++ top] = i;
            used[i] = true;
        }
        used[0] = false;
        for (int i = n - 1; i >= 0; i -- ) {
            if (used[i]) continue;
            while (top >= 2 && area(points[hull[top - 1]], points[hull[top]], points[i]) > 0)
                top -- ;
            hull[ ++ top] = i;
        }
        top -- ;
        vector<vector<int>> res;
        for (int i = 1; i <= top; i ++ ) res.push_back(points[hull[i]]);
        return res;
    }
};
