class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        if(start == target) return 0;
        unordered_set<string> S;
        for(auto& dead : deadends) S.insert(dead); 
        if(S.count(start)) return -1;
        queue<string> que;
        que.push(start);
        unordered_map<string, int> dst;
        dst[start] = 0;
        while(que.size()) {
            auto t = que.front();
            que.pop();
            for(int i = 0; i < 4; i++) {
                for(int j = -1; j <= 1; j += 2) {
                    auto state = t;
                    state[i] = (state[i] - '0' + j + 10) % 10 + '0';
                    if(!S.count(state) && !dst.count(state)) {
                        dst[state] = dst[t] + 1;
                        if(state == target) return dst[state];
                        que.push(state);
                    }
                }
            }
        }
        return -1;
    }
};