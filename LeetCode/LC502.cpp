class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<pair<int,int>> q;
        int n = Profits.size();
        for(int i = 0; i < n; i++) q.push_back({Capital[i], Profits[i]});
        sort(q.begin(), q.end());
        priority_queue<int> heap;
        int i = 0;
        while(k--) {
            while(i < n && q[i].first <= W) heap.push(q[i].second), i++;
            if(heap.empty()) break;
            auto t = heap.top();
            W += t;
            heap.pop();
        }
        return W;
    }
};