class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](const string& a, const string& b) {
            int x = a.find(' '), y = b.find(' ');
            auto a1 = a.substr(0, x), b1 = b.substr(0, y);
            auto a2 = a.substr(x + 1), b2 = b.substr(y + 1);
            auto a3 = isdigit(a2[0]), b3 = isdigit(b2[0]);
            if (a3 != b3) return a3 < b3;
            if (a3) return false;
            if (a2 != b2) return a2 < b2;
            return a1 < b1;
        });
        return logs;
    }
};