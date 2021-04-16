class Solution {
public:
    bool check(unordered_map<char, int>& a, unordered_map<char, int>& b) {
        for (auto [k, v]: b)
            if (a[k] < v)
                return false;
        return true;
    }

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> T;
        for (auto c: licensePlate)
            if (c != ' ' && !isdigit(c))
                T[tolower(c)] ++ ;
        string res;
        for (auto& w: words) {
            unordered_map<char, int> cnt;
            for (auto c: w) cnt[c] ++ ;
            if (check(cnt, T)) {
                if (res.empty() || res.size() > w.size())
                    res = w;
            }
        }
        return res;
    }
};