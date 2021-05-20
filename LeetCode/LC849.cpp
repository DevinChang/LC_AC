class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(seats[i]) continue;
            int j = i + 1;
            while(j < n && !seats[j]) j++;
            if(!i || j == n) res = max(res, j - i);
            else {
                res = max(res, (j - i + 1) / 2);
            }
        }
        return res;
    }
};