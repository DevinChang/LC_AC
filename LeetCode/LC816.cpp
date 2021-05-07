class Solution {
public:
    vector<string> get(string s) {
        vector<string> res;
        if (s.size() == 1 || s[0] != '0') res.push_back(s);
        for (int i = 1; i < s.size(); i ++ ) {
            string a = s.substr(0, i), b = s.substr(i);
            if (a.size() > 1 && a[0] == '0') continue;  // 有前导零
            if (b.back() == '0') continue;  // 末尾多余的零
            res.push_back(a + '.' + b);
        }
        return res;
    }

    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        s = s.substr(1, s.size() - 2);
        for (int i = 1; i < s.size(); i ++ ) {
            auto l = get(s.substr(0, i)), r = get(s.substr(i));
            for (auto x: l)
                for (auto y: r)
                    res.push_back('(' + x + ", " + y + ')');
        }
        return res;
    }
};