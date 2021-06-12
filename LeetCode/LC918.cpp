class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
		int n = nums.size();
		vector<int> s(n * 2 + 1);
		for(int i = 1; i <= 2 * n; i++) s[i] = s[i-1] + nums[(i-1) % n];

		deque<int> q;
		q.push_front(0);
		int res = INT_MIN;
		for(int i = 1; i <= n * 2; i++) {
			while(q.size() && i - q.front() > n)  q.pop_front();
			res = max(res, s[i] - s[q.front()]);
			while(q.size() && s[q.back()] >= s[i]) q.pop_back();
			q.push_back(i);
		}
		return res;
    }
};