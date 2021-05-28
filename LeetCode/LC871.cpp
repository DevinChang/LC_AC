class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target, 0});
        priority_queue<int> heap;
        int sum = startFuel, res = 0;
        for(auto p : stations){
            int x = p[0], y = p[1];
            while(heap.size() && sum < x){
                sum += heap.top();
                heap.pop();
                res++;
            }
            if(sum < x) return -1;
            heap.push(y);
        }
        return res;
    }
};