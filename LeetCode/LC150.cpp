#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;




int evalRPN(vector<string> &tokens) {
    int ret = 0;
    stack<int> st;
    int n = tokens.size();
    for(int i = 0; i < n; i++){
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            int b = st.top(); st.pop();
            ret = st.top(); st.pop(); // 因为是逆序计算，所以这里要将被除数后出栈
            if(tokens[i] == "+") ret += b;
            else if (tokens[i] == "-") ret -= b;
            else if (tokens[i] == "*") ret *= b;
            else if (tokens[i] == "/") ret /= b;
            st.push(ret);
        }
        else {
            st.push(stoi(tokens[i]));
        }
    }
    return st.top();
}
