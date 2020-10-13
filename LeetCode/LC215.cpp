

int quicksort(vector<int> &nums, int l, int r, int k){
    if(l == r) return nums[l];
    int pivot = nums[l],i = l , j = r;
    while(i < j)
    {
        while(i < j && nums[j] >= pivot) j --;
        while(i < j && nums[i] <= pivot) i ++;
        if(i < j)
            swap(nums[i],nums[j]);
    }
    swap(nums[i],nums[l]);
    if(i - l >= k) return quicksort(nums,l, i - 1, k);
    else if(i - l + 1 == k) return nums[i];
    else return quicksort(nums,i + 1,r,k - (i - l  + 1)); 
}



int findKthLargest(vector<int> &nums, int k){
    int n = nums.size();
    return quicksort(nums, 0, n-1, n-k+1);
}