class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> S;
        for(auto &s : bank) S.insert(s);
        unordered_map<string, int> dst;
        queue<string> q;
        q.push(start);
        dst[start] = 0;
        char chars[4] = {'A', 'T', 'C', 'G'};
        while(q.size()) {
            auto t = q.front();
            q.pop();
            for(int i = 0; i < t.size(); i++) {
                auto s = t;
                for(char c : chars) {
                    s[i] = c;
                    if(S.count(s) && dst.count(s) == 0) {
                        dst[s] = dst[t] + 1;
                        if(s == end) return dst[s];
                        q.push(s);
                    }
                }
            }
        }
        return -1;
    }
};