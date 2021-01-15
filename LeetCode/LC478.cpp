class Solution {
public:
    double r, x, y;

    Solution(double radius, double x_center, double y_center) {
        r = radius, x = x_center, y = y_center;
    }
    
    vector<double> randPoint() {
        // 生成[-1,1]之间的数
        double a = (double)rand() / RAND_MAX * 2 - 1;
        double b = (double)rand() / RAND_MAX * 2 - 1;
        if(a * a + b * b > 1) return randPoint();
        return {x + r * a, y + r * b};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */