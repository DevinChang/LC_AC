class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n == 0) return 0;
        vector<int> diff(n-1);
        for(int i = 0; i < n-1; i++) diff[i] = A[i+1]-A[i];
        int last = 0, ans = 0;
        for(int i = 1; i < n-1; i++) {
            if(diff[i] != diff[i-1]){
                ans += (i - last) * (i - last - 1) / 2;
                last = i;
            }
        }
        ans += (n - last - 1) * (n - last-2) / 2;
        return ans;
    }
};