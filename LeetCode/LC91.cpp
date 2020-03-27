//
// Created by devinchang on 2019/12/20.
//

#include "util.h"


int numDecoding(string s){
    if(s.size() < 1)
        return 0;
    if(s[0] == '0')
        return 0;
    int len = s.size();
    vector<int> dp(len+1, 0);
    dp[len] = 1;
    for(int i = len-1; i >= 0; i--){
        if(s[i] == '0')
            dp[i] = 0;
        else{
            dp[i] += dp[i+1];
            if(i < len-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))){
                dp[i] += dp[i+2];
            }
        }
    }
    return dp[0];
}



int main(){
    string line;
    while(getline(cin, line)){
        string s = stringToString(line);
        int ret = numDecoding(s);
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

