//
// Created by devinchang on 2019/12/17.
//

#include "util.h"


int longestValidParentheses(string s){
    if(s.size() < 1)
        return 0;
    int len = s.size();
    int maxlen = 0;
    vector<int> dp(len, 0);
    for(int i = 1; i < len; i++){
        if(s[i] == ')'){
            if(s[i-1] == '('){
                dp[i] = i >= 2 ? (dp[i-2] + 2) : 2;
            }
            else{
                if(i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(')
                    dp[i] = dp[i-1] + 2 + (i-dp[i-1]-2 > 0 ? dp[i-dp[i-1]-2] : 0);
            }
        }
        maxlen = max(maxlen, dp[i]);
    }
    return maxlen;
}


int main(){
    string line;
    while(getline(cin, line)){
        string s = stringToString(line);

        int ret = longestValidParentheses(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

