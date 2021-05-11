class Solution {
public:
    struct Task {
        int d, p;
        bool operator <(const Task t) const {
            return d < t.d;
        }
    };
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<Task>tasks(n);
        for(int i = 0; i < n; i++) {
            tasks[i] = {difficulty[i], profit[i]};
        }
        sort(tasks.begin(), tasks.end());
        sort(worker.begin(), worker.end());
        int res = 0, maxp = 0;
        for(int i = 0, j = 0; i < worker.size(); i++) {
            while(j < n && tasks[j].d <= worker[i]) {
                maxp = max(maxp, tasks[j].p);
                j++;
            }
            res += maxp;
        }
        return res;
    }
};