class Solution {
public:
    int minAddToMakeValid(string s) {
		stack<int> st;
		int res = 0;
		for(auto c : s) {
			if(c == '(') st.push(0);
			else {
				if(st.empty()) res++;
				else st.pop();
			}
		}
		res += st.size();
		return res;
    }
};