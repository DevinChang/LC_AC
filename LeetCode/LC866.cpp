class Solution {
public:

    bool check(int x) {
        if (x < 2 || (x > 2 && x % 2 == 0))
            return false;
        for (int i = 3; i * i <= x; i += 2)
            if (x % i == 0)
                return false;
        return true;
    }

    int make(int x) {
        string s = to_string(x), t = s;
        reverse(t.begin(), t.end());
        s.pop_back();
        return stoi(s + t);
    }

    int primePalindrome(int N) {
        if (N > 7 && N <= 11)
            return 11;

        for (int i = 1; i <= 99999; i++) {
            int x = make(i);
            if (x >= N && check(x))
                return x;
        }

        return -1;
    }
};