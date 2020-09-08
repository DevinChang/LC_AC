
int findPeakElement(vector<int> &nums) {
    int l = 0, r = nums.size()-1;
    while (l < r){
        int mid = (l + r) / 2;
        if(nums[mid] > nums[mid+1]) r = mid;
        else l = mid + 1;
    }
    return r;
}