class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = arr.size() - 2;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(arr[mid-1] < arr[mid]) l = mid;
            else r = mid - 1;
        }
        return r;
    }
};