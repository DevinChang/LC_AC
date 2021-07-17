class Solution {
public:
    bool isValid(string s) {
		stack<char> st;
		for(auto &c : s) {
			if(c == '(' || c == '[' || c == '{') st.push(c);
			else {
				if(st.size() && abs(st.top() - c) <= 2) st.pop();
				else return false;
			}
		}
		return st.size() == 0;
    }
};