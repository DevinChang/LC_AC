
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q;
    vector<int> ret;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(q.size() && i - k + 1 > q.front()) q.pop_front();
        while(q.size() && nums[i] >= nums[q.back()]) q.pop_back();
        q.push_back(i);
        if(i >= k - 1) ret.push_back(nums[q.front()]);
    }
    return ret;
}