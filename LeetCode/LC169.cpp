



int majorityElement(vector<int> &nums){
    int cnt = 0, candidate = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if (cnt == 0) candidate = nums[i];
        if(nums[i] == candidate) cnt++;
        else cnt --;
    }
    return candidate;
}