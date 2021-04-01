class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> hash;
        for(auto& w : words) hash[w]++;
        typedef pair<int,string> PIS;
        vector<PIS> ws;
        for(auto [k, v] : hash) ws.push_back({v,k});
        auto cmp = [](PIS a, PIS b) {
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        };
        make_heap(ws.begin(), ws.end(), cmp);
        vector<string> res;
        while(k--) {
            res.push_back(ws[0].second);
            pop_heap(ws.begin(), ws.end(), cmp);
            ws.pop_back();
        }
        return res;
    }
};