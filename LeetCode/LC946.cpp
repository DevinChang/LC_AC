class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> st;
		int k = 0;
		int n = popped.size();
		for(auto x : pushed) {
			st.push(x);
			while(st.size() && k < n && st.top() == popped[k]) {
				st.pop();
				k++;
			}
		}
		return k == n;
    }
};