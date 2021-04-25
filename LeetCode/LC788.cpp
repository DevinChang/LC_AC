class Solution {
public:
    unordered_set<int> s1, s2;
    bool judge(int x) {
        bool is_diff = false;
        while(x) {
            int d = x % 10;
            if(s2.count(d)) is_diff = true;
            else if (!s1.count(d)) return false;
            x /= 10;
        }
        return is_diff;
    }
    int rotatedDigits(int N) {
        s1 = unordered_set<int>{0, 1, 8};
        s2 = unordered_set<int>{2, 5, 6, 9};
        int res = 0;
        for(int i = 0; i <= N; i++) {
            if(judge(i)) res++;
        }
        return res;
    }
};