class Solution {
public:
    string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = s.size(), m = indexes.size();
        vector<int> id(m);
        for(int i = 0; i < m; i++) id[i] = i;
        sort(id.begin(), id.end(), [&](int a, int b) {
            return indexes[a] < indexes[b];
        });
        for(int i = m - 1; i >= 0; i--) {
            int k = id[i];
            if(s.substr(indexes[k], sources[k].size()) == sources[k]) {
                s = s.substr(0, indexes[k]) + targets[k] + s.substr(indexes[k] + sources[k].size());
            }
        }
        return s;
    }
};