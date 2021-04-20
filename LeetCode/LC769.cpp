class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        for(int i = 0, x = 0; i < arr.size(); i++) {
            x = max(arr[i], x);
            if(x == i) res++;
        }
        return res;
    }
};