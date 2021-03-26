class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        for(int i = 0; i < n - k - 1; i++) res[i] = i+1;
        int u = n - k -1 ;
        int i = n - k, j = n;
        while(u < n) {
            res[u++] = i++;
            if(u < n) res[u++] = j--;
        }
        return res;
    }
};