class Solution {
public:
    vector<int> nums;
    vector<bool> st;

    bool dfs(int start, int cur, int len, int cnt) {
        // 如果已经拼出了三根，则最后一根可以拼出来，这是因为，最后一根失败的情况被剪枝了
        if(cnt == 3) return true;
        // 当前火柴的拼接长度已经是满足变长
        if(cur == len) return dfs(0, 0, len, cnt+1);
        for(int i = start; i < nums.size(); i++){
            if(st[i]) continue;
            if(cur + nums[i] <= len) {
                st[i] = true;
                if(dfs(i+1, cur+nums[i], len, cnt)) return true;
                st[i] = false;
            }
            // 如果是第一根或者最后一根失败的，就剪掉当前分支
            if(!cur || cur + nums[i] == len) return false;
            // 将当前相同长度的木棍跳过
            while(i + 1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        return false;
    }

    bool makesquare(vector<int>& _nums) {
        nums = _nums;
        if(nums.empty()) return false;
        st.resize(nums.size());
        int sum = 0;
        for(auto x : nums) sum += x;
        if(sum % 4 != 0) return false;
        sum /= 4;
        sort(nums.begin(), nums.end());
        return dfs(0, 0, sum, 0);
    }
};