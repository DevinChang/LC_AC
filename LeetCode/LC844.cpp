class Solution {
public:
    string get(string& s) {
        string res;
        for (auto c: s)
            if (c == '#') {
                if (res.size()) res.pop_back();
            } else {
                res += c;
            }
        return res;
    }

    bool backspaceCompare(string s, string t) {
        return get(s) == get(t);
    }
};