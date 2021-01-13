class Solution {
public:
    bool check(int r, vector<int> &houses, vector<int> &heaters) {
        int n = heaters.size();
        for(int i = 0, j = 0; i < houses.size(); i ++) {
            while(j < n && abs(houses[i] - heaters[j]) > r) j++;
            if(j == n) return false;
        }
        return true;
    }


    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = max(*houses.rbegin(), *heaters.rbegin());
        while(l < r) {
            int mid = (l + r) >> 1;
            if(check(mid, houses, heaters)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};