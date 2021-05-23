class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>stk;
        stk.push(0);
        for(auto c : s){
            if(c == '('){
                stk.push(0);
            } else {
                int t = stk.top();
                stk.pop();
                if(!t) t = 1;
                else t *= 2;
                stk.top() += t;
            }
        }
        return stk.top();
    }
};