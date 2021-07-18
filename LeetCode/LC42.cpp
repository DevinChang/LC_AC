class Solution {
public:
    int trap(vector<int>& height) {
		stack<int> stk;
		int res = 0;
		for(int i = 0; i < height.size(); i++) {
			while(stk.size() && height[stk.top()] <= height[i]) {
				int t = stk.top();
				stk.pop();
				if(stk.empty()) break;
				res += (i - stk.top() - 1) * (min(height[stk.top()], height[i]) - height[t]);
			}
			stk.push(i);
		}
		return res;
    }
};