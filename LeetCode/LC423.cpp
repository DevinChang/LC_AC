class Solution {
public:
    string originalDigits(string s) {
        string name[] = {
            "zero", "one", "two", "three", "four", "five",
            "six", "seven", "eight", "nine"
        };
        int ord[] = {0, 8, 3, 2, 6, 4, 5, 1, 7, 9};
        unordered_map<char, int> cnt;
        for (auto c: s) cnt[c] ++ ;
        string res;
        for (int x: ord) {
            while (true) {
                bool flag = true;
                for (auto c: name[x])
                    if (!cnt[c]) {
                        flag = false;
                        break;
                    }
                    if (flag) {
                        res += to_string(x);
                        for (auto c: name[x]) cnt[c] -- ;
                    }
                    else break;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};