typedef long long LL;

class Solution {
public:
    vector<int> get(string& s, LL a, LL b) {
        vector<int> res = {(int)a, (int)b};
        string t = to_string(a) + to_string(b);
        while (t.size() < s.size()) {
            auto c = a + b;
            if (c > INT_MAX) return {};
            res.push_back(c);
            t += to_string(c);
            a = b, b = c;
        }
        if (t != s) return {};
        return res;
    }

    vector<int> splitIntoFibonacci(string s) {
        for (int i = 1; i <= 10 && i < s.size(); i ++ )
            for (int j = i + 1; j <= i + 10 && j < s.size(); j ++ ) {
                auto a = stoll(s.substr(0, i)), b = stoll(s.substr(i, j - i));
                auto res = get(s, a, b);
                if (res.size()) return res;
            }

        return {};
    }
};