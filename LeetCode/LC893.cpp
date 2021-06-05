class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> S;
        for (auto& w: words) {
            string a, b;
            for (int i = 0; i < w.size(); i += 2) {
                a += w[i];
                b += w[i + 1];
            }
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            S.insert(a + b);
        }
        return S.size();
    }
};