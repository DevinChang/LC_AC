class Solution {
public:
    string toLowerCase(string str) {
        string res;
        for(auto c : str) res += tolower(c);
        return res;
    }
};