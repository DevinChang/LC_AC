class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        vector<int> res;
        for (int x : nums) hash[x] ++;
        int n = nums.size();
        vector<int>s(n + 1, 0);
        for (auto &p : hash) s[p.second] ++ ;
        int i = n, t = 0;
        while (t < k) t += s[i -- ];
        for (auto &p : hash)
            if (p.second > i)
                res.push_back(p.first);
        return res;
    }
};