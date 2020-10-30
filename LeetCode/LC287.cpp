
int findDuplicate(vector<int>& nums) {
    int a = 0, b = 0;
    while(1){
        a = nums[a];
        b = nums[nums[b]];
        if(a == b){
            a = 0;
            while(a != b){
                a = nums[a];
                b = nums[b];
            }
            return a;
        }
    }
    return -1;
}


// 抽屉原理
int countRande(vector<int> &nums, int start, int end){
    int count = 0;
    for(auto n : nums){
        if(n >= start && n <= end)
            ++count;
    }
    return count;
}

int findDuplicate(vector<int>& nums) {
    if(nums.size() < 1)
        return -1;
    int start = 1, end = nums.size() - 1;
    while(start <= end){
        int mid = ((end - start) >> 1) + start;
        int count = countRande(nums, start, mid);
        if(start == end){
            if(count > 1)
                return start;
            else break;
        }
        if(count > (mid - start + 1))
            end = mid;
        else
            start = mid + 1;
    }
    return -1;
}