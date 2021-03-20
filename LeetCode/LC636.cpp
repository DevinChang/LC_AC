class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        stack<int> stk;
        int last = 0;
        for(auto& log : logs) {
            // 格式化找到函数id和执行时间
            int x = log.find(':'), y = log.substr(x+1).find(':') + x + 1;
            int id = stoi(log.substr(0, x));
            int ts = stoi(log.substr(y+1));
            if(log.substr(x+1, y-x-1) == "start") {
                if(stk.size()) res[stk.top()] += ts - last;
                last = ts;
                stk.push(id);
            } else {
                res[id] += ts - last + 1;
                last = ts + 1;
                stk.pop();
            }
        }
        return res;
    }
};