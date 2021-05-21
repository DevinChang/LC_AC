class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<int> id(n);
        for(int i = 0; i < n; i++) id[i] = i;
        sort(id.begin(), id.end(), [&](int a, int b) {
            return position[a] < position[b];
        });
        int res = n;
        const double eps = 1e-6;
        double last = 0;
        for(int i = n - 1; i >= 0; i--){
            double t = (target - position[id[i]]) / (double)speed[id[i]];
            if(t < last + eps) res--;
            else last = t;
        }
        return res;
    }
};