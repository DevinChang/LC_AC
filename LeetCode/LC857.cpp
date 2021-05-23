class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>> r(n);
        for(int i = 0; i < n; i++) {
            r[i] = make_pair(1.0 *quality[i] /wage[i], i);
        }
        sort(r.begin(), r.end());
        reverse(r.begin(), r.end());
        priority_queue<pair<int,int>> heap;
        double res = 1e10;
        int sum = 0;
        for(int i = 0; i < n; i++){
            double tmp = 1.0 * wage[r[i].second];
            double ratio = 1.0 * wage[r[i].second] / quality[r[i].second];
            if(heap.size() == k - 1) { 
                res = min(res, tmp + sum * ratio);
            }
            if(k > 1){
                if(heap.size() < k -1){
                    heap.push(make_pair(quality[r[i].second], r[i].second));
                    sum += quality[r[i].second];
                } else {
                    if(quality[r[i].second] < heap.top().first){
                        sum -= heap.top().first;
                        heap.pop();
                        heap.push(make_pair(quality[r[i].second], r[i].second));
                        sum += quality[r[i].second];
                    }
                }
            }
        }
        return res;
    }
};