class Solution {
public:
    int flipLights(int n, int m) {
        if (n == 0) return 1;
        if (n == 1) {
            if (m == 0) return 1;
            return 2;
        }
        if (n == 2) {
            if (m == 0) return 1;
            if (m == 1) return 3;
            return 4;
        }

        if (m == 0) return 1;
        if (m == 1) return 4;
        if (m == 2) return 7;
        return 8;
    }
};