class Solution {
public:
    bool check(int a, int b, int c, int d) {
        return a < b && c < d && b > c && d > a;
    }

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return check(rec1[0], rec1[2], rec2[0], rec2[2])
            && check(rec1[1], rec1[3], rec2[1], rec2[3]);
    }
};