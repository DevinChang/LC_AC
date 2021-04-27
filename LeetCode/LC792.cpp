typedef pair<int,int> PII;
#define x first
#define y second

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<PII> ps[26];
        for(int i = 0; i < words.size(); i++) {
            ps[words[i][0]-'a'].push_back({i, 0});
        }
        int res = 0;
        for(auto c : s) {
            vector<PII> buf;
            for(auto &p : ps[c-'a']) {
                if(p.y + 1 == words[p.x].size()) res++;
                else buf.push_back({p.x, p.y+1});
            }
            ps[c-'a'].clear();
            for(auto &p : buf) {
                ps[words[p.x][p.y]-'a'].push_back(p);
            }
        }
        return res;
    }
};