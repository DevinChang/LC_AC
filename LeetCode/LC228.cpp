

vector<string> summaryRanges(vector<int> &nums) {
    int n = nums.size();
    vector<string> ret;
    for(int i = 0; i < n; i++){
        int j = i+1;
        while(j < n && nums[j-1]+1 == nums[j]) j++;
        // 不连续的情况
        if(j == i+1) ret.push_back(to_string(nums[i]));
        else {
            ret.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
        }
        i = j - 1;
    }
    return ret;
}